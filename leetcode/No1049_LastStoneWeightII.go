package lc1049

import "math"

var IDX_SHFIT int = 1500

func lastStoneWeightII(stones []int) int {

	dp := make([][]bool, len(stones)+1)
	for i := 0; i < len(stones)+1; i++ {
		dp[i] = make([]bool, 3001)
	}
	dp[0][IDX_SHFIT] = true

	for i, st := range stones {

		for j := -1500; j < 1500-st; j++ {
			if dp[i][j+IDX_SHFIT] {
				dp[i+1][j+IDX_SHFIT+st] = true
			}
		}
		for j := st - 1500; j < 1500; j++ {
			if dp[i][j+IDX_SHFIT] {
				dp[i+1][j+IDX_SHFIT-st] = true
			}
		}
	}

	return findAbsMin(dp[len(stones)])
}

func abs(i int) int {
	if i < 0 {
		return -i
	}
	return i
}
func min(i, j int) int {
	if i < j {
		return i
	}
	return j
}

func findAbsMin(arr []bool) int {
	var retVal int = math.MaxInt
	for i, elem := range arr {
		if elem {
			retVal = min(retVal, abs(i-IDX_SHFIT))
		}
	}
	return retVal
}
