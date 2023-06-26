package lc2679

import (
	"math"
	"sort"
)

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

func matrixSum(nums [][]int) int {

	for i, _ := range nums {
		sort.Slice(nums[i], func(j, k int) bool {
			return nums[i][j] < nums[i][k]
		})
	}

	var ret int = 0
	for i := 0; i < len(nums[0]); i += 1 {
		opt := math.MinInt32
		for j := 0; j < len(nums); j += 1 {
			opt = max(opt, nums[j][i])
		}
		ret += opt
	}
	return ret
}
