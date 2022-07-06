package lc407

import "container/heap"

var dirs [][]int = [][]int{
	{-1, 0}, {1, 0}, {0, -1}, {0, 1},
}

type obj struct {
	x, y, h int
}

type PriorQueue []obj

func (p *PriorQueue) Len() int           { return len(*p) }
func (p *PriorQueue) Less(i, j int) bool { return (*p)[i].h < (*p)[j].h }
func (p *PriorQueue) Swap(i, j int)      { (*p)[i], (*p)[j] = (*p)[j], (*p)[i] }

func (p *PriorQueue) Push(x interface{}) {
	// Push and Pop use pointer receivers because they modify the slice's length,
	// not just its contents.
	*p = append(*p, x.(obj))
}

func (p *PriorQueue) Pop() interface{} {
	elem := (*p)[len(*p)-1]
	(*p) = (*p)[:len(*p)-1]
	return elem
}

func trapRainWater(heightMap [][]int) int {

	h := &PriorQueue{}
	heap.Init(h)

	var m, n int = len(heightMap), len(heightMap[0])

	for i := 0; i < m; i++ {
		for j := 0; j < n; j++ {
			if i == 0 || j == 0 || i == m-1 || j == n-1 {
				heap.Push(h, obj{i, j, heightMap[i][j]})
				heightMap[i][j] = -1
			}
		}
	}

	var objTmp obj
	var retCnt int = 0
	for h.Len() > 0 {
		objTmp = heap.Pop(h).(obj)

		for _, dir := range dirs {
			i, j := objTmp.x+dir[0], objTmp.y+dir[1]
			if i >= 0 && j >= 0 && i < m && j < n {
				if tmpH := heightMap[i][j]; tmpH >= 0 {
					retCnt += max(0, objTmp.h-tmpH)
					heap.Push(h, obj{i, j, max(objTmp.h, tmpH)})
					heightMap[i][j] = -1
				}
			}
		}
	}

	return retCnt
}

func max(i, j int) int {
	if i > j {
		return i
	}
	return j
}
