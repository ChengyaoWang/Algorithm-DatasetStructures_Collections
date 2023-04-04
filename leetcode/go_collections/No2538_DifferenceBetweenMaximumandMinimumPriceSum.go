package lc2538

type pair struct {
	totalSum, totalSumWoLeaf int64
}

func maxOutput(n int, edges [][]int, price []int) int64 {

	g := make([][]int, n)
	for _, e := range edges {
		g[e[0]] = append(g[e[0]], e[1])
		g[e[1]] = append(g[e[1]], e[0])
	}

	var ans int64 = 0
	dfs(0, -1, &g, &price, &ans)
	return ans
}

func dfs(n, pre int, g *[][]int, price *[]int, ans *int64) pair {

	ret := pair{
		totalSum:       int64((*price)[n]),
		totalSumWoLeaf: int64(0),
	}

	for _, nei := range (*g)[n] {
		if nei == pre {
			continue
		}

		p := dfs(nei, n, g, price, ans)
		(*ans) = max(*ans, ret.totalSum+p.totalSumWoLeaf)
		(*ans) = max(*ans, ret.totalSumWoLeaf+p.totalSum)
		ret.totalSum = max(ret.totalSum, p.totalSum+int64((*price)[n]))
		ret.totalSumWoLeaf = max(ret.totalSumWoLeaf, p.totalSumWoLeaf+int64((*price)[n]))
	}

	return ret
}

func max(a, b int64) int64 {
	if a > b {
		return a
	}
	return b
}
