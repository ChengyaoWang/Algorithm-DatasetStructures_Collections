package lc1253

func reconstructMatrix(upper int, lower int, colsum []int) [][]int {

	var ret [][]int = make([][]int, 2)
	ret[0] = make([]int, len(colsum))
	ret[1] = make([]int, len(colsum))

	for i, v := range colsum {
		if v == 1 {
			if upper < lower {
				lower -= 1
				ret[1][i] = 1
			} else {
				upper -= 1
				ret[0][i] = 1
			}
		} else if v == 2 {
			upper -= 1
			lower -= 1
			ret[0][i] = 1
			ret[1][i] = 1
			colsum[i] = 0
		}

		if lower < 0 || upper < 0 {
			break
		}
	}

	if lower != 0 || upper != 0 {
		return [][]int{}
	}
	return ret
}
