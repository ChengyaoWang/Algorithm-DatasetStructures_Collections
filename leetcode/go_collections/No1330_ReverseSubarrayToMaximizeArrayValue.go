package lc1330

import "math"

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

func abs(a int) int {
	if a < 0 {
		return -a
	}
	return a
}

func maxValueAfterReverse(nums []int) int {
	baseVal := 0
	minmaxVal, maxminVal := math.MaxInt32, math.MinInt32
	optDelta := math.MinInt32
	for i := 1; i < len(nums); i += 1 {
		baseVal += abs(nums[i] - nums[i-1])
		// Normal Conditions
		minmaxVal = min(minmaxVal, max(nums[i], nums[i-1]))
		maxminVal = max(maxminVal, min(nums[i], nums[i-1]))
		optDelta = max(optDelta, 2*(maxminVal-minmaxVal))

		// Boundary Conditions
		optDelta = max(optDelta, abs(nums[len(nums)-1]-nums[i-1])-abs(nums[i]-nums[i-1]))
		if i < len(nums)-1 {
			optDelta = max(optDelta, abs(nums[i+1]-nums[0])-abs(nums[i+1]-nums[i]))
		}
	}

	return baseVal + max(0, optDelta)
}
