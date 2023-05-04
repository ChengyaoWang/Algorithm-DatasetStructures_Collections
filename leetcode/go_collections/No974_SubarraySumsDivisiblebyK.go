package lc974

func mod(a, b int) int {
	res := a % b
	if res < 0 {
		res += b
	}
	return res
}

func subarraysDivByK(nums []int, k int) int {
	var ret int = 0
	dp, cumSum := make([]int, k), 0
	dp[0] = 1
	for _, elem := range nums {
		cumSum += elem
		modn := mod(cumSum, k)
		ret += dp[modn]
		dp[modn] += 1
	}
	return ret
}
