package lc1261

type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

type FindElements struct {
	root *TreeNode
	val  map[int]bool
}

func dfs(root *TreeNode, v int, m *map[int]bool) {
	if root == nil {
		return
	}

	(*m)[v] = true
	dfs(root.Left, 2*v+1, m)
	dfs(root.Right, 2*v+2, m)
	return
}

func Constructor(root *TreeNode) FindElements {

	m := make(map[int]bool)
	dfs(root, 0, &m)
	return FindElements{
		root: root,
		val:  m,
	}
}

func (this *FindElements) Find(target int) bool {
	_, ok := this.val[target]
	if ok {
		return true
	}
	return false
}

/**
* Your FindElements object will be instantiated and called as such:
* obj := Constructor(root);
* param_1 := obj.Find(target);
 */
