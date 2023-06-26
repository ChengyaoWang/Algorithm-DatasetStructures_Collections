package lc743

import (
	"container/heap"
	"math"
)

type Edge struct {
	e, t int
}

type PriorityQueue []Edge

func (pq PriorityQueue) Len() int { return len(pq) }
func (pq PriorityQueue) Less(i, j int) bool {
	return pq[i].t < pq[j].t
}
func (pq PriorityQueue) Swap(i, j int) {
	pq[i], pq[j] = pq[j], pq[i]
}
func (pq *PriorityQueue) Push(x any) {
	item := x.(Edge)
	*pq = append(*pq, item)
}
func (pq *PriorityQueue) Pop() any {
	old := *pq
	n := len(old)
	item := old[n-1]
	*pq = old[0 : n-1]
	return item
}

func max(a ...int) int {
	ret := math.MinInt32
	for _, elem := range a {
		if elem > ret {
			ret = elem
		}
	}
	return ret
}

func networkDelayTime(times [][]int, n int, k int) int {

	adjMx := make([][]Edge, n)
	for i := 0; i < n; i += 1 {
		adjMx[i] = make([]Edge, 0)
	}
	for _, e := range times {
		elem := Edge{e: e[1] - 1, t: e[2]}
		adjMx[e[0]-1] = append(adjMx[e[0]-1], elem)
	}

	minDist := make([]int, n)
	for i, _ := range minDist {
		minDist[i] = math.MaxInt32
	}
	var pq PriorityQueue = []Edge{}
	pq.Push(Edge{e: k - 1, t: 0})
	heap.Init(&pq)

	for len(pq) > 0 {
		node := heap.Pop(&pq).(Edge)
		if node.t > minDist[node.e] {
			continue
		} else {
			minDist[node.e] = node.t
			for _, neighbor := range adjMx[node.e] {
				if newT := node.t + neighbor.t; newT < minDist[neighbor.e] {
					heap.Push(&pq, Edge{
						e: neighbor.e,
						t: newT,
					})
				}
			}
		}
	}

	if ret := max(minDist...); ret == math.MaxInt32 {
		return -1
	} else {
		return ret
	}
}
