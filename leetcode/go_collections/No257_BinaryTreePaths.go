package lc257

import "strconv"

type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

func binaryTreePaths(root *TreeNode) []string {

	ret := make([]string, 0)
	treeTraverse(root, "", &ret)
	return ret
}

func treeTraverse(root *TreeNode, path string, ret *[]string) {

	path += strconv.Itoa(root.Val)
	if root.Left == nil && root.Right == nil {
		*ret = append(*ret, path)
		return
	}

	path += "->"
	if root.Left != nil {
		treeTraverse(root.Left, path, ret)
	}
	if root.Right != nil {
		treeTraverse(root.Right, path, ret)
	}

	return
}
