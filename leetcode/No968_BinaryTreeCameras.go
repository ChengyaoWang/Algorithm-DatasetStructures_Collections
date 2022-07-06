package lc968

type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

var cnt int

func minCameraCover(root *TreeNode) int {
	cnt = 0

	if a := helper(root); a == 0 {
		cnt++
	}

	return cnt
}

func helper(root *TreeNode) int {

	if root == nil {
		return 2
	}

	l := helper(root.Left)
	r := helper(root.Right)

	if l == 0 || r == 0 {
		cnt++
		return 1
	} else if l == 1 || r == 1 {
		return 2
	}
	return 0
}
