package lc1458

import "math"

func maxDotProduct(nums1 []int, nums2 []int) int {
	var l1, l2 int = len(nums1), len(nums2)

	dp := make([][]int, l1)
	for i := 0; i < l1; i++ {
		dp[i] = make([]int, l2)
	}
	dp[0][0] = nums1[0] * nums2[0]
	// Initialize
	for i := 1; i < l1; i++ {
		dp[i][0] = max(dp[i-1][0], nums1[i]*nums2[0])
	}
	for j := 1; j < l2; j++ {
		dp[0][j] = max(dp[0][j-1], nums1[0]*nums2[j])
	}

	for i := 1; i < l1; i++ {
		for j := 1; j < l2; j++ {
			dp[i][j] = max(dp[i-1][j], dp[i][j-1], max(dp[i-1][j-1], 0)+nums1[i]*nums2[j])
		}
	}

	return dp[l1-1][l2-1]
}

func max(arr ...int) int {
	var retElem int = math.MinInt
	for _, v := range arr {
		if retElem < v {
			retElem = v
		}
	}
	return retElem
}
