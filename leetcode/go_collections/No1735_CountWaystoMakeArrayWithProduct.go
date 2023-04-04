package lc1735

import "math/big"

var primes [25]int = [25]int{2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97}

func primeFactorize(n, k int) int {

	ret := big.NewInt(1)
	for _, elem := range primes {
		totalCnt := 0
		for k%elem == 0 {
			totalCnt += 1
			k /= elem
		}

		for i := n; i <= (n + totalCnt - 1); i += 1 {
			ret.Mul(ret, big.NewInt(int64(i)))
		}
		for i := 1; i <= totalCnt; i += 1 {
			ret.Div(ret, big.NewInt(int64(i)))
		}
	}

	if k != 1 {
		ret.Mul(ret, big.NewInt(int64(n)))
	}

	ret.Mod(ret, big.NewInt((1000000007)))

	return int(ret.Int64())
}

func waysToFillArray(queries [][]int) []int {

	ret := make([]int, 0)

	for _, q := range queries {
		tmp := primeFactorize(q[0], q[1])
		ret = append(ret, tmp)
	}

	return ret
}
