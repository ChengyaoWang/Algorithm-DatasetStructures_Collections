package lc1222

func abs(i int) int {
	if i < 0 {
		return -i
	}
	return i
}

func queensAttacktheKing(queens [][]int, king []int) [][]int {

	ret := make([][]int, 0)
	slot := make([][]int, 8)

	hash := func(di, dj int) (int, bool) {
		val := 0

		if abs(di) == abs(dj) {
			val += 4
			if di > 0 {
				val += 2
			}
			if dj > 0 {
				val += 1
			}
		} else if di == 0 || dj == 0 {
			if di+dj > 0 {
				val += 2
			}
			if di == 0 {
				val += 1
			}
		} else {
			return -1, false
		}

		return val, true
	}

	var dis int
	for _, q := range queens {

		di := q[0] - king[0]
		dj := q[1] - king[1]

		if h, ok := hash(di, dj); ok {
			if slot[h] == nil {
				dis = 100
			} else {
				dis = abs(slot[h][0]) + abs(slot[h][1])
			}

			if abs(di)+abs(dj) < dis {
				slot[h] = []int{di, dj}
			}
		}
	}

	for _, q := range slot {
		if q != nil {
			ret = append(ret, []int{q[0] + king[0], q[1] + king[1]})
		}
	}

	return ret
}
