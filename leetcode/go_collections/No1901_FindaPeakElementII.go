package lc1901

func max(a, b int) int {
	if a < b {
		return b
	}
	return a
}

func maxElem(idx int, mat *[][]int, mem *[][]int) (int, int) {

	m := len(*mat)
	if idx == -1 || idx == m {
		return -1, -1
	}

	if len((*mem)[idx]) > 0 {
		return (*mem)[idx][0], (*mem)[idx][1]
	}

	ret, ret_i := -1, -1
	for i, elem := range (*mat)[idx] {
		if elem > ret {
			ret = elem
			ret_i = i
		}
	}

	(*mem)[idx] = []int{ret, ret_i}
	return ret, ret_i
}

func findPeakGrid(mat [][]int) []int {
	low, up := -1, len(mat)+1

	mem := make([][]int, len(mat))
	for low < up {
		mid := (low + up) / 2
		b, bi := maxElem(mid, &mat, &mem)
		a, _ := maxElem(mid-1, &mat, &mem)
		c, _ := maxElem(mid+1, &mat, &mem)
		if b >= max(a, c) {
			return []int{mid, bi}
		}
		if a > max(b, c) {
			up = mid + 1
		} else {
			low = mid
		}
	}
	return []int{-1, -1}
}
