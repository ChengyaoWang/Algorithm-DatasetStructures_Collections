package lc1785

func abs(a int) int {
	if a < 0 {
		return -a
	}
	return a
}

func minElements(nums []int, limit int, goal int) int {

	res := goal
	for _, elem := range nums {
		res -= elem
	}

	return (abs(res) + limit - 1) / limit
}
