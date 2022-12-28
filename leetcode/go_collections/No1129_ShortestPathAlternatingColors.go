type Node struct {
	val, rb, d int
	prev, next *Node
}

type Queue struct {
	head, tail *Node
	size       int
}

func (q *Queue) Init() {
	q.tail = &Node{}
	q.head = &Node{}
	q.head.next = q.tail
	q.tail.prev = q.head
	q.size = 0
}

func (q *Queue) Push(v, c, d int) {
	newNode := Node{v, c, d, q.tail.prev, q.tail}
	q.tail.prev.next = &newNode
	q.tail.prev = &newNode
	q.size++
}

func (q *Queue) Pop() *Node {
	node := q.head.next
	q.head.next = node.next
	node.next.prev = q.head
	q.size--
	return node
}

func shortestAlternatingPaths(n int, red_edges [][]int, blue_edges [][]int) []int {
	r := make(map[int][]int)
	b := make(map[int][]int)
	seen := make([]int, n)
	retList := make([]int, n)

	for _, p := range red_edges {
		_, ok := r[p[0]]
		if !ok {
			r[p[0]] = make([]int, 0)
		}
		r[p[0]] = append(r[p[0]], p[1])
	}
	for _, p := range blue_edges {
		_, ok := b[p[0]]
		if !ok {
			b[p[0]] = make([]int, 0)
		}
		b[p[0]] = append(b[p[0]], p[1])
	}

	q := Queue{}
	q.Init()

	q.Push(0, 1, 0)
	q.Push(0, 2, 0)

	for q.size != 0 {
		node := q.Pop()
		seen[node.val] |= node.rb
		if node.val > 0 && retList[node.val] == 0 {
			retList[node.val] = node.d
		}
		if node.rb == 1 {
			for _, nei := range r[node.val] {
				if seen[nei]&2 == 0 {
					q.Push(nei, 2, node.d+1)
				}
			}
		} else if node.rb == 2 {
			for _, nei := range b[node.val] {
				if seen[nei]&1 == 0 {
					q.Push(nei, 1, node.d+1)
				}
			}
		}
	}

	for i, v := range retList {
		if i != 0 && v == 0 {
			retList[i] = -1
		}
	}

	return retList
}