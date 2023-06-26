package lc1779

import "math"

func abs(a int) int {
	if a < 0 {
		return -a
	}
	return a
}
func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

func nearestValidPoint(x int, y int, points [][]int) int {

	disFunc := func(x2, y2 int) int {
		return abs(x-x2) + abs(y-y2)
	}

	minDis, idx := math.MaxInt32, -1
	for i, p := range points {
		if p[0] == x || p[1] == y {
			dis := disFunc(p[0], p[1])
			if minDis > dis {
				idx = i
				minDis = dis
			}
		}
	}

	return idx
}
