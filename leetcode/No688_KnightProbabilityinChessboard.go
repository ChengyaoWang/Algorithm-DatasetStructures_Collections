package lc688

var moves [][]int = [][]int{
	{-1, 2}, {-1, -2}, {1, 2}, {1, -2},
	{-2, 1}, {-2, -1}, {2, 1}, {2, -1},
}

func knightProbability(n int, k int, row int, column int) float64 {

	dp := make([][][]float64, k+1)
	for i := 0; i <= k; i++ {
		dp[i] = make([][]float64, n)
		for j := 0; j < n; j++ {
			dp[i][j] = make([]float64, n)
		}
	}

	dp[0][row][column] = 1.

	for dk := 1; dk <= k; dk++ {
		for _, m := range moves {
			for di := max(0, m[0]); di < n+min(0, m[0]); di++ {
				for dj := max(0, m[1]); dj < n+min(0, m[1]); dj++ {
					dp[dk][di-m[0]][dj-m[1]] += dp[dk-1][di][dj] / 8.
				}
			}
		}
	}

	var sum float64 = 0.

	for di := 0; di < n; di++ {
		for dj := 0; dj < n; dj++ {
			sum += dp[k][di][dj]
		}
	}

	return sum

}

func min(i, j int) int {
	if i < j {
		return i
	}
	return j
}
func max(i, j int) int {
	if i > j {
		return i
	}
	return j
}
