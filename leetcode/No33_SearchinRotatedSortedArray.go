package lc33

func search(nums []int, target int) int {

	low, up := 0, len(nums)
	var mid int

	for {
		mid = (low + up) / 2
		if nums[low] == nums[mid] {
			break
		} else if nums[low] < nums[mid] {
			if nums[low] <= target && target < nums[mid] {
				up = mid
			} else {
				low = mid
			}
		} else {
			if target < nums[mid] || nums[low] <= target {
				up = mid
			} else {
				low = mid
			}
		}
	}

	if nums[low] != target {
		return -1
	}
	return low
}
