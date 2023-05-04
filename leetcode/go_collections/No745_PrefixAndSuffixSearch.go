// Here is the Definition for Nodes in Trie

type TrieNode struct {
	MaxIdx   int
	children []*TrieNode
}

type Trie struct {
	root *TrieNode
}

func max(i, j int) int {
	if i > j {
		return i
	} else {
		return j
	}
}

func (t *Trie) Push(s string, idx int) {
	PushHelper(t.root, 0, s, idx)
}

func PushHelper(node *TrieNode, i int, s string, idx int) {
	node.MaxIdx = max(node.MaxIdx, idx)
	if i == len(s) {
		return
	} else {
		if node.children[s[i]-'a'] == nil {
			node.children[s[i]-'a'] = &TrieNode{-1, make([]*TrieNode, 27)}
		}
		PushHelper(node.children[s[i]-'a'], i+1, s, idx)
		return
	}
}

func (t *Trie) Query(s string) int {
	node := t.root
	for i := 0; i < len(s); i++ {
		node = node.children[s[i]-'a']
		if node == nil {
			return -1
		}
	}
	return node.MaxIdx
}

type WordFilter struct {
	t Trie
}

func WordCompose(i int, s string) string {
	return s[i:] + "{" + s
}

func Constructor(words []string) WordFilter {
	t := Trie{&TrieNode{-1, make([]*TrieNode, 27)}}

	for idx, w := range words {
		for i := 0; i < len(w); i++ {
			wordToPush := WordCompose(i, w)
			t.Push(wordToPush, idx)
		}
	}
	return WordFilter{t}
}

func (this *WordFilter) F(prefix string, suffix string) int {
	q := suffix + "{" + prefix
	return this.t.Query(q)
}

/**
 * Your WordFilter object will be instantiated and called as such:
 * obj := Constructor(words);
 * param_1 := obj.F(prefix,suffix);
 */
