package lc2448

import (
	"math"
	"sort"
)

type elem struct {
	n, v int64
}

func min(a, b int64) int64 {
	if a < b {
		return a
	}
	return b
}

func minCost(nums []int, cost []int) int64 {

	n := len(nums)
	arr := make([]elem, n)
	var curTotalCost int64 = 0
	var curCumCost_r, curCumCost_l int64 = 0, 0
	for i, _ := range nums {

		a := elem{
			n: int64(nums[i]),
			v: int64(cost[i]),
		}

		arr = append(arr, a)
		curTotalCost += a.v * a.n
		curCumCost_r += a.v
	}

	sort.Slice(arr, func(a, b int) bool {
		return arr[a].n < arr[b].n
	})

	var ret, prev int64 = math.MaxInt64, 0

	for _, elem := range arr {
		curTotalCost -= (elem.n - prev) * (curCumCost_r - curCumCost_l)
		curCumCost_r -= (elem.v)
		curCumCost_l += (elem.v)
		ret = min(ret, curTotalCost)
		prev = elem.n
	}

	return ret
}
