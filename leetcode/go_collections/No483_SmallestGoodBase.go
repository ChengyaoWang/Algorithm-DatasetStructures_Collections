package lc483

import (
	"math"
	"strconv"
)

func smallestGoodBase(n string) string {

	N, _ := strconv.ParseUint(n, 10, 64)

	var low, mid, up uint64
	var sum, i, term uint64

	for m := uint64(65); m > uint64(1); m-- {

		low, up = 2, uint64(math.Pow(float64(N), 1./float64(m)))+1

		for low < up {

			mid = low + (up-low)/2

			i, sum, term = 0, 0, 1
			for ; (i <= m) && (sum < N); i++ {
				sum += term
				term *= mid
			}

			if sum == N {
				return strconv.Itoa(int(mid))
			} else if sum < N {
				low = mid + 1
			} else {
				up = mid
			}
		}
	}

	return strconv.Itoa(int(N - 1))
}
