package lc2070

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

func upper_bound(key int, items *[][]int) int {
	lo, hi := 0, len(*items)
	for lo < hi {
		mid := lo + (hi-lo)/2
		if key < (*items)[mid][0] {
			hi = mid
		} else {
			lo = mid + 1
		}

	}

	if lo < len(*items) && (*items)[lo][0] <= key {
		lo += 1
	}

	return lo - 1
}

func maximumBeauty(items [][]int, queries []int) []int {

	sort.Slice(items, func(i, j int) bool {
		return items[i][0] < items[j][0]
	})

	elem := math.MinInt32
	for i, n := range items {
		elem = max(elem, n[1])
		items[i][1] = elem
	}

	ret := make([]int, 0)
	for _, q := range queries {
		idx := upper_bound(q, &items)
		if idx == -1 {
			ret = append(ret, 0)
		} else {
			ret = append(ret, items[idx][1])
		}
	}

	return ret
}
