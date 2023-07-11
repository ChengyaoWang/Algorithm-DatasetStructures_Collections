import functools

import numpy as np

import jax
import jax.numpy as jnp

jax.config.update('jax_enable_x64', True)

class BsplineBase(object):
    def __init__(self) -> None:
        pass
    
    @staticmethod
    def evaluate_spline_np(
        x: np.ndarray, t: np.ndarray,
        k: int, extrapolate: bool = True
    ) -> np.ndarray:

        Nt, Dt = t.shape
        k1 = k + 1

        x_a = np.tile(x[:, np.newaxis], reps = (1, Dt))

        t_0, t_1 = t, np.roll(t, shift = -1, axis = 1)
        t_k, t_k1 = t_0, t_1

        t_extrapo = np.concatenate([
                np.ones(shape = (Nt, k1)) * float('-inf') if extrapolate else t_0[:, :k1],
                t_0[:, k1: -k1],
                np.ones(shape = (Nt, k1)) * float('inf') if extrapolate else t_0[:, -k1:],
            ], axis = 1
        )

        dp_0 = np.logical_and(
            np.less_equal(t_extrapo, x_a),
            np.less(x_a, np.roll(t_extrapo, shift = -1, axis = 1)),
        ).astype(np.float64)

        for _ in range(k):
            # c1 part
            t_k = np.roll(t_k, shift = -1, axis = 1)
            c_1 = np.subtract(x_a, t_0) / np.subtract(t_k, t_0) * dp_0
            
            # c2 part
            t_k1  = np.roll(t_k1, shift = -1, axis = 1)
            c_2 = np.subtract(t_k1, x_a) / np.subtract(t_k1, t_1) * np.roll(dp_0, shift = -1, axis = 1)

            c_1 = np.where(t_k  == t_0, 0., c_1)
            c_2 = np.where(t_k1 == t_1, 0., c_2)

            dp_0 = c_1 + c_2

        return dp_0[..., :-k1]

    @staticmethod
    def evaluate_spline_jnp(
        x: jnp.array, t: jnp.array,
        k: int, extrapolate: bool = True
    ) -> np.ndarray:

        Nt, Dt = t.shape
        k1 = k + 1

        x_a = jnp.tile(x[:, np.newaxis], reps = (1, Dt))

        t_0, t_1 = t, jnp.roll(t, shift = -1, axis = 1)
        t_k, t_k1 = t_0, t_1

        t_extrapo = jnp.concatenate([
                jnp.ones(shape = (Nt, k1)) * float('-inf') if extrapolate else t_0[:, :k1],
                t_0[:, k1: -k1],
                jnp.ones(shape = (Nt, k1)) * float('inf') if extrapolate else t_0[:, -k1:],
            ], axis = 1
        )

        dp_0 = jnp.logical_and(
            jnp.less_equal(t_extrapo, x_a),
            jnp.less(x_a, jnp.roll(t_extrapo, shift = -1, axis = 1)),
        ).astype(jnp.float64)

        for _ in range(k):
            # c1 part
            t_k = jnp.roll(t_k, shift = -1, axis = 1)
            c_1 = jnp.subtract(x_a, t_0) / jnp.subtract(t_k, t_0) * dp_0
            
            # c2 part
            t_k1 = jnp.roll(t_k1, shift = -1, axis = 1)
            c_2  = jnp.subtract(t_k1, x_a) / jnp.subtract(t_k1, t_1) * jnp.roll(dp_0, shift = -1, axis = 1)

            c_1 = jnp.where(t_k  == t_0, 0., c_1)
            c_2 = jnp.where(t_k1 == t_1, 0., c_2)

            dp_0 = c_1 + c_2

        return dp_0[..., :-k1]

class Bspline_FixedKnots(BsplineBase):
    
    def __init__(self,
        xt: np.ndarray,
        k: int, extrapolate: bool = True
    ) -> None:
        
        super().__init__()

        self.k: int = k
        self.extrapolate: bool = extrapolate

        self.x_ctrl: np.ndarray = None
        self.xt: np.ndarray = np.expand_dims(xt, axis = 0)
 
    def fit(self,
        X: np.ndarray, y: np.ndarray,
    ) -> 'Bspline_FixedKnots':

        Nt = X.shape
        xt = np.repeat(a = self.xt, repeats = Nt, axis = 0)

        bs_coef = self.evaluate_spline_np(
            x = X, t = xt, k = self.k,
            extrapolate = self.extrapolate
        )

        self.x_ctrl = np.linalg.inv(bs_coef.T @ bs_coef) @ bs_coef.T @ y

        return self
    
    def predict(self,
        X: np.ndarray
    ) -> np.ndarray:
    
        Nt = X.shape
        xt = np.repeat(a = self.xt, repeats = Nt, axis = 0)

        bs_coef = self.evaluate_spline_np(
            x = X, t = xt, k = self.k,
            extrapolate = self.extrapolate
        )

        y = np.sum(bs_coef * self.x_ctrl, axis = 1)

        return y

class Bspline_DynamicKnots(BsplineBase):
    
    def __init__(self,
        knot_num: int,
        k: int, extrapolate: bool = True,
    ) -> None:

        super().__init__()

        self.knot_num: int = knot_num
        self.k: int = k
        self.extrapolate: bool = extrapolate
    
        self.x_t: jnp.array = None
        self.x_tb: jnp.array = None
        self.x_ctrl: jnp.array = None

        self.jax_rand_key = jax.random.PRNGKey(seed = 42)

    def _forward(self,
        x: jnp.array, x_t: jnp.array,
        x_ctrl: jnp.array,
    ) -> jnp.array:

        Nt = x.shape[0]

        x_ctrl = jnp.expand_dims(x_ctrl, axis = 0)
        x_ctrl = jnp.repeat(x_ctrl, repeats = Nt, axis = 0)

        x_t = jnp.expand_dims(x_t, axis = 0)
        x_t = jnp.repeat(x_t, repeats = Nt, axis = 0)

        x_comp = self.evaluate_spline_jnp(
            x = x, t = x_t,
            k = self.k, extrapolate = self.extrapolate
        )

        return jnp.sum(x_comp * x_ctrl, axis = 1)

    @functools.partial(jax.jit, static_argnums = 0)
    def forward(self,
        x: jnp.array, x_t: jnp.array, x_tb: jnp.array,
        x_ctrl: jnp.array,
        y: jnp.array,
    ) -> float:

        # x_t = jnp.power(x_t, 2) + 0.05
        # x_t = jnp.cumsum(x_t, axis = 0) + x_tb

        y_prd = self._forward(x = x, x_t = x_t, x_ctrl = x_ctrl)
        loss = jnp.mean((y_prd - y) * (y_prd - y), axis = None)
        return loss

    def fit(self,
        X: np.ndarray, y: np.ndarray
    ) -> 'Bspline_DynamicKnots':

        Xjnp = jnp.array(object = X)
        yjnp = jnp.array(object = y)

        # x_t = jnp.ones(shape = (self.knot_num)) * 0.1
        # x_t = jnp.sqrt(x_t)
        x_tb = jnp.array(object = 0.)
        x_t = jnp.linspace(0.2, 0.8, num = self.knot_num)

        x_ctrl = jax.random.normal(
            key = self.jax_rand_key,
            shape = (self.knot_num - self.k - 1,)
        )

        lr: float = 5e-2

        for i in range(5000):

            v, grads = jax.value_and_grad(self.forward, argnums = (1, 2, 3))(Xjnp, x_t, x_tb, x_ctrl, yjnp)

            # x_t = x_t - lr * grads[0]
            # x_tb = x_tb - lr * grads[1]
            x_ctrl = x_ctrl - lr * grads[2]

            print(f'Step: {i}, loss = {v}', end = '\r', flush = True)
            # print(f'{jnp.cumsum(jnp.power(x_t, 2), axis = 0) + x_tb}')

        self.x_t = x_t
        self.x_tb = x_tb
        self.x_ctrl = x_ctrl

        return self

    def predict(self,
        X: np.ndarray
    ) -> np.ndarray:

        Xjnp = jnp.array(object = X)

        x_t = self.x_t

        # x_t = jnp.power(self.x_t, 2) + 0.05
        # x_t = jnp.cumsum(x_t, axis = 0) + self.x_tb

        y = self._forward(x = Xjnp, x_t = x_t, x_ctrl = self.x_ctrl)

        return np.array(y)