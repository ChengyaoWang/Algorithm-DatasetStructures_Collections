package lc1828

func countPoints(points [][]int, queries [][]int) []int {

	dis := func(x1, y1 int, x2, y2 int) int {
		return (x1-x2)*(x1-x2) + (y1-y2)*(y1-y2)
	}

	ret := make([]int, 0)
	for _, q := range queries {
		r_sqr := q[2] * q[2]
		cnter := 0
		for _, p := range points {
			if d := dis(q[0], q[1], p[0], p[1]); d <= r_sqr {
				cnter += 1
			}
		}
		ret = append(ret, cnter)
	}

	return ret
}
