package lc1372

type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

func longestZigZag(root *TreeNode) int {
	var ret int = 0
	dfs(root, true, &ret)
	return ret - 1
}

func dfs(root *TreeNode, isLeftChild bool, ret *int) int {
	if root == nil {
		return 0
	}

	l := dfs(root.Left, true, ret)
	r := dfs(root.Right, false, ret)

	(*ret) = max(*ret, l+1)
	(*ret) = max(*ret, r+1)
	if isLeftChild {
		return r + 1
	}
	return l + 1
}
