package lc2358

import "math"

func maximumGroups(grades []int) int {

	var root float64 = -1. + math.Sqrt(1.+8.*float64(len(grades)))
	root /= 2.
	return int(root)
}
