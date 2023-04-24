package lc1685

func getSumAbsoluteDifferences(nums []int) []int {

	ret := make([]int, len(nums))
	for i := len(nums) - 1; i > 0; i -= 1 {
		nums[i] -= nums[i-1]
		ret[0] += nums[i] * (len(nums) - i)
	}
	nums[0] = 0
	for i := 1; i < len(nums); i += 1 {
		ret[i] = ret[i-1]
		ret[i] -= (len(nums) - i) * nums[i]
		ret[i] += i * nums[i]
	}
	return ret
}
