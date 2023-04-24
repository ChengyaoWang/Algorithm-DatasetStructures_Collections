package lc1879

import "math"

func minimumXORSum(nums1 []int, nums2 []int) int {
	n := len(nums1)
	dp := make([]int, 1<<n)
	for i, _ := range dp {
		dp[i] = math.MaxInt32
	}
	_ = helper(0, 0, &dp, &nums1, &nums2)
	return dp[0]
}

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

func helper(depth, mask int, dp, nums1, nums2 *[]int) int {
	if depth == len(*nums1) {
		return 0
	}
	if (*dp)[mask] == math.MaxInt32 {
		for j := 0; j < len(*nums1); j += 1 {
			if mask&(1<<j) == 0 {
				delta := helper(depth+1, mask|1<<j, dp, nums1, nums2)
				(*dp)[mask] = min((*dp)[mask], (*nums1)[depth]^(*nums2)[j]+delta)
			}
		}
	}
	return (*dp)[mask]
}
