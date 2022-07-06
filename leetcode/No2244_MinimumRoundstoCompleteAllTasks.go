package lc224

import "math"

func minimumRounds(tasks []int) int {

	var maxCnt int = math.MinInt
	counter := make(map[int]int)

	for _, v := range tasks {
		if _, ok := counter[v]; ok {
			counter[v]++
		} else {
			counter[v] = 1
		}

		maxCnt = max(maxCnt, counter[v])
	}

	if _, ok := counter[1]; ok {
		return -1
	}

	dp := make([]int, max(maxCnt+1, 2))
	dp[0] = 0
	dp[1] = math.MaxInt
	dp[2] = 1

	for i := 3; i <= maxCnt; i++ {
		dp[i] = min(dp[i-2], dp[i-3]) + 1
	}

	var retCnt int = 0
	for _, v := range counter {
		if v == 1 {
			return -1
		}
		retCnt += dp[v]
	}

	return retCnt
}

func max(i, j int) int {
	if i > j {
		return i
	}
	return j
}

func min(i, j int) int {
	if i < j {
		return i
	}
	return j
}
