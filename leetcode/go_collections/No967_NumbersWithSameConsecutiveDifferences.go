package lc967

// Since We have to Give all combinations, we use dfs
func dfs(path, depth, n, k int, res *[]int) {
	if depth == n {
		*res = append(*res, path)
		return
	}

	lastDigit := path % 10
	if lastDigit >= k {
		dfs(path*10+lastDigit-k, depth+1, n, k, res)
	}
	if lastDigit < 10-k && k != 0 {
		dfs(path*10+lastDigit+k, depth+1, n, k, res)
	}

	return
}

func numsSameConsecDiff(n int, k int) []int {

	ret := make([]int, 0)
	for i := 1; i < 10; i += 1 {
		dfs(i, 1, n, k, &ret)
	}
	return ret
}
