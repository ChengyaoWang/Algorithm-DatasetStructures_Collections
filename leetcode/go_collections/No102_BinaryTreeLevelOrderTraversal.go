package lc102

type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

type queue struct {
	arr []*TreeNode
}

func (q *queue) Push(ptr *TreeNode) {
	q.arr = append(q.arr, ptr)
}
func (q *queue) Pop() *TreeNode {
	elem := q.arr[0]
	q.arr = q.arr[1:]
	return elem
}
func (q queue) Empty() bool {
	return len(q.arr) == 0
}

func levelOrder(root *TreeNode) [][]int {

	ret := make([][]int, 0)
	m := queue{arr: make([]*TreeNode, 0)}
	n := queue{arr: make([]*TreeNode, 0)}

	if root != nil {
		m.Push(root)
	}

	for !m.Empty() {
		row := make([]int, 0)
		for !m.Empty() {
			elem := m.Pop()
			row = append(row, elem.Val)
			if elem.Left != nil {
				n.Push(elem.Left)
			}
			if elem.Right != nil {
				n.Push(elem.Right)
			}
		}
		m, n = n, m
		ret = append(ret, row)
	}

	return ret
}
