package lc_1453

import (
	"math"
	"sort"
)

type elem struct {
	theta float64
	cnt   int
}

func numPoints(darts [][]int, r int) int {

	var N int = len(darts)
	p2p_dis := make([][]float64, N)
	for i := 0; i < N; i++ {
		p2p_dis[i] = make([]float64, N)
	}

	var dis_tmp float64
	for i := 0; i < N; i++ {
		for j := i + 1; j < N; j++ {
			dis_tmp = l2_dis(darts[i], darts[j])
			p2p_dis[i][j] = dis_tmp
			p2p_dis[j][i] = dis_tmp
		}
	}

	// Iterate Though Every Point
	var A, B float64
	var maxCnt int = 1
	for i, p := range darts {
		h := make([]elem, 0)

		for j, pi := range darts {

			if (i != j) && (p2p_dis[i][j] <= (2. * float64(r))) {

				A = math.Acos(p2p_dis[i][j] / (2. * float64(r)))
				B = math.Atan2(float64(pi[1]-p[1]), float64(pi[0]-p[0]))
				h = append(h, elem{B + A, -1})
				h = append(h, elem{B - A, 1})
			}
		}

		sort.Slice(h, func(i, j int) bool {
			if h[i].theta != h[j].theta {
				return h[i].theta < h[j].theta
			}
			return h[i].cnt > h[j].cnt
		})

		var runningSum int = 1
		for _, pi := range h {
			runningSum += pi.cnt
			maxCnt = max(maxCnt, runningSum)
		}
	}
	return maxCnt
}

func max(i, j int) int {
	if i > j {
		return i
	}
	return j
}

func l2_dis(i, j []int) float64 {
	var d1 float64 = float64(i[0] - j[0])
	var d2 float64 = float64(i[1] - j[1])
	return math.Sqrt(d1*d1 + d2*d2)
}
