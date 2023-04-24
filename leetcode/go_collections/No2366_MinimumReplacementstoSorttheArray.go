package lc2366

func minimumReplacement(nums []int) int64 {
	n := len(nums)
	prevElem := nums[n-1]
	var ret int64 = 0
	for i := n - 2; i >= 0; i -= 1 {

		if prevElem >= nums[i] {
			prevElem = nums[i]
			continue
		}

		reps := (nums[i] + prevElem - 1) / prevElem
		ret += int64(reps) - 1
		prevElem = nums[i] / reps
	}
	return ret
}
