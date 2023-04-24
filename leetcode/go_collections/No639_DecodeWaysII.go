package lc639

func numDecodings(s string) int {
	var MOD_NUM int64 = 1000000007
	dp_cur := make([]int64, 3)
	dp_cur[0] = 1

	for _, c := range s {
		dp_next := make([]int64, 3)

		if c == '*' {
			dp_next[0] = 9*dp_cur[0] + 9*dp_cur[1] + 6*dp_cur[2]
			dp_next[1] = dp_cur[0]
			dp_next[2] = dp_cur[0]
		} else {
			dp_next[0] = dp_cur[1]
			if c > '0' {
				dp_next[0] += dp_cur[0]
			}
			if c <= '6' {
				dp_next[0] += dp_cur[2]
			}
			if c == '1' {
				dp_next[1] = dp_cur[0]
			}
			if c == '2' {
				dp_next[2] = dp_cur[0]
			}
		}

		dp_cur[0] = dp_next[0] % MOD_NUM
		dp_cur[1] = dp_next[1] % MOD_NUM
		dp_cur[2] = dp_next[2] % MOD_NUM
	}

	return int(dp_cur[0])
}
