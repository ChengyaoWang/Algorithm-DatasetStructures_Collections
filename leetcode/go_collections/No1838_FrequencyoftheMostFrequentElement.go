package lc1838

import "sort"

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

func maxFrequency(nums []int, k int) int {

	ret := 1
	lo, cumSum := 0, 0

	sort.Slice(nums, func(i, j int) bool { return nums[i] < nums[j] })

	for hi := 1; hi < len(nums); hi += 1 {
		cumSum += (nums[hi] - nums[hi-1]) * (hi - lo)
		for cumSum > k && lo < hi {
			cumSum -= nums[hi] - nums[lo]
			lo += 1
		}
		ret = max(ret, hi-lo+1)
	}
	return ret
}
