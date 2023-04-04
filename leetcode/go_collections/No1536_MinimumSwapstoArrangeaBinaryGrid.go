package lc1536

func rightMostOnes(vec []int) int {
	i := len(vec) - 1
	for ; i >= 0; i -= 1 {
		if vec[i] == 1 {
			break
		}
	}
	return i
}

func minSwaps(grid [][]int) int {

	num := make([]int, 0)
	n := len(grid)

	for i := 0; i < n; i += 1 {
		num = append(num, rightMostOnes(grid[i]))
	}

	var ret int = 0
	for i := 0; i < n; i += 1 {
		if num[i] > i {
			ii := i + 1
			for ii < n && num[ii] > i {
				ii += 1
			}
			if ii == n {
				return -1
			}
			ret += ii - i
			for i < ii {
				num[ii-1], num[ii] = num[ii], num[ii-1]
				ii -= 1
			}
		}
	}

	return ret
}
