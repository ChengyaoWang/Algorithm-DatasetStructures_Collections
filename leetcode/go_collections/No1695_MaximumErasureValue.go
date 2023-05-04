package lc1695

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

func maximumUniqueSubarray(nums []int) int {
	curSum, maxSum := 0, -1
	cnter := make(map[int]int)

	lo := 0
	for _, elem := range nums {
		cnter[elem] += 1
		curSum += elem
		for cnter[elem] > 1 {
			cnter[nums[lo]] -= 1
			curSum -= nums[lo]
			lo += 1
		}
		maxSum = max(maxSum, curSum)
	}

	return maxSum
}
