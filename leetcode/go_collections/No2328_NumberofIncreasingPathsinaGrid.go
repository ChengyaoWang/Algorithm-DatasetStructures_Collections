package lc2328

import "container/heap"

type Elem struct {
	i, j, v int
}

type PriorityQueue []*Elem

func (q PriorityQueue) Len() int            { return len(q) }
func (q PriorityQueue) Less(i, j int) bool  { return (q)[i].v < (q)[j].v }
func (q PriorityQueue) Swap(i, j int)       { (q)[i], (q)[j] = (q)[j], (q)[i] }
func (q *PriorityQueue) Push(e interface{}) { (*q) = append((*q), e.(*Elem)) }
func (q *PriorityQueue) Pop() interface{} {
	n := len(*q)
	e := (*q)[n-1]
	(*q) = (*q)[:n-1]
	return e
}

func countPaths(grid [][]int) int {

	var m int = len(grid)
	var n int = len(grid[0])
	pq := make(PriorityQueue, 0)

	for i := 0; i < m; i++ {
		for j := 0; j < n; j++ {
			pq = append(pq, &Elem{i, j, grid[i][j]})
		}
	}
	heap.Init(&pq)

	dp := make([][]int64, m)
	for i := 0; i < m; i++ {
		dp[i] = make([]int64, n)
	}

	var ret int64 = 0
	checkBoundary := func(i, j int) bool {
		return 0 <= i && i < m && 0 <= j && j < n
	}
	for pq.Len() > 0 {
		elem := heap.Pop(&pq).(*Elem)
		i, j, v := (*elem).i, (*elem).j, (*elem).v
		dp[i][j] = 1
		if checkBoundary(i+1, j) && v > grid[i+1][j] {
			dp[i][j] = (dp[i][j] + dp[i+1][j]) % 1000000007
		}
		if checkBoundary(i-1, j) && v > grid[i-1][j] {
			dp[i][j] = (dp[i][j] + dp[i-1][j]) % 1000000007
		}
		if checkBoundary(i, j+1) && v > grid[i][j+1] {
			dp[i][j] = (dp[i][j] + dp[i][j+1]) % 1000000007
		}
		if checkBoundary(i, j-1) && v > grid[i][j-1] {
			dp[i][j] = (dp[i][j] + dp[i][j-1]) % 1000000007
		}

		ret += dp[i][j] % 1000000007
	}

	return int(ret)
}
