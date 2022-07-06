package lc516

func longestPalindromeSubseq(s string) int {

	var N int = len(s)

	dp := make([][]int, N)
	for i := 0; i < N; i++ {
		dp[i] = make([]int, N)
	}

	for i := 0; i < N; i++ {
		for j := 0; j < N-i; j++ {
			if i == 0 {
				dp[j][j+i] = 1
			} else if i == 1 {
				if s[j] == s[j+i] {
					dp[j][j+i] = 2
				} else {
					dp[j][j+i] = 1
				}
			} else {
				dp[j][j+i] = max(dp[j][j+i-1], dp[j+1][j+i])
				if s[j] == s[j+i] {
					dp[j][j+i] = max(dp[j][j+i], dp[j+1][j+i-1]+2)
				} else {
					dp[j][j+i] = max(dp[j][j+i], dp[j+1][j+i-1])
				}

			}
		}
	}

	return dp[0][N-1]
}

func max(i, j int) int {
	if i > j {
		return i
	}
	return j
}
