package lc1937

func max(a, b int64) int64 {
	if a > b {
		return a
	}
	return b
}
func abs(a int) int64 {
	if a < 0 {
		return int64(-a)
	}
	return int64(a)
}
func genAuxArray(arr []int64) ([]int64, []int64) {
	n := len(arr)
	l, r := make([]int64, n), make([]int64, n)
	for i, _ := range arr {
		if i == 0 {
			l[i] = arr[i]
			r[n-1-i] = arr[n-1-i]
		} else {
			l[i] = max(l[i-1]-1, arr[i])
			r[n-1-i] = max(r[n-i]-1, arr[n-1-i])
		}
	}
	return l, r
}

func maxPoints(points [][]int) int64 {
	m, n := len(points), len(points[0])
	dp := make([][]int64, 2)
	dp[0] = make([]int64, n)
	dp[1] = make([]int64, n)

	for i, elem := range points[0] {
		dp[0][i] = int64(elem)
	}

	for i := 1; i < m; i += 1 {
		l, r := genAuxArray(dp[(i+1)%2])
		for j := 0; j < n; j += 1 {
			dp[i%2][j] = int64(points[i][j]) + max(l[j], r[j])
		}
	}

	var ret int64 = -1
	for _, elem := range dp[(m-1)%2] {
		ret = max(ret, elem)
	}

	return ret
}
