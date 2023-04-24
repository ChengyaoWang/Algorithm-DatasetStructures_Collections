package lc1493

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

func longestSubarray(nums []int) int {

	var ret int = 0
	var zeroValCount int = 0

	l := 0
	for r, elem := range nums {
		if elem == 0 {
			zeroValCount += 1
		}
		for zeroValCount > 1 {
			if nums[l] == 0 {
				zeroValCount -= 1
			}
			l += 1
		}
		ret = max(ret, r-l)
	}
	return ret

}
