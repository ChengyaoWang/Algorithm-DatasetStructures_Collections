/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * type NestedInteger struct {
 * }
 *
 * // Return true if this NestedInteger holds a single integer, rather than a nested list.
 * func (this NestedInteger) IsInteger() bool {}
 *
 * // Return the single integer that this NestedInteger holds, if it holds a single integer
 * // The result is undefined if this NestedInteger holds a nested list
 * // So before calling this method, you should have a check
 * func (this NestedInteger) GetInteger() int {}
 *
 * // Set this NestedInteger to hold a single integer.
 * func (n *NestedInteger) SetInteger(value int) {}
 *
 * // Set this NestedInteger to hold a nested list and adds a nested integer to it.
 * func (this *NestedInteger) Add(elem NestedInteger) {}
 *
 * // Return the nested list that this NestedInteger holds, if it holds a nested list
 * // The list length is zero if this NestedInteger holds a single integer
 * // You can access NestedInteger's List element directly if you want to modify it
 * func (this NestedInteger) GetList() []*NestedInteger {}
 */

// Self-Defined Stacks
type Pair struct {
	idx int
	ni  []*NestedInteger
}

func (p *Pair) isInt() bool {
	return p.ni[p.idx].IsInteger()
}
func (p *Pair) isEnd() bool {
	return p.idx == len(p.ni)
}

type Stack struct {
	arr []Pair
}

func (q *Stack) Push(elem Pair) {
	q.arr = append(q.arr, elem)
}
func (q *Stack) Pop() Pair {
	elem := q.arr[len(q.arr)-1]
	q.arr = q.arr[:len(q.arr)-1]
	return elem
}
func (q *Stack) Empty() bool {
	return len(q.arr) == 0
}
func (q *Stack) Back() *Pair {
	return &q.arr[len(q.arr)-1]
}
func (q *Stack) Size() int {
	return len(q.arr)
}

// Solution Begins
type NestedIterator struct {
	q Stack
}

func Constructor(nestedList []*NestedInteger) *NestedIterator {
	retItem := NestedIterator{Stack{make([]Pair, 0)}}
	p := Pair{0, nestedList}
	retItem.q.Push(p)

	for len(p.ni) > 0 && !p.isInt() {
		p = Pair{0, p.ni[p.idx].GetList()}
		retItem.q.Push(p)
	}

	return &retItem
}

func (this *NestedIterator) Next() int {
	p := this.q.Back()
	retItem := p.ni[p.idx].GetInteger()
	p.idx += 1
	// Recur Back
	for this.q.Size() > 0 && p.isEnd() {
		this.q.Pop()
		if this.q.Size() == 0 {
			break
		}
		p = this.q.Back()
		p.idx += 1
	}

	if this.q.Size() > 0 {
		// Recur Downward
		tmp := *p
		for !tmp.isInt() {
			tmp = Pair{0, tmp.ni[tmp.idx].GetList()}
			this.q.Push(tmp)
		}
	}
	fmt.Println(retItem)
	fmt.Println(this.q.arr)
	return retItem
}

func (this *NestedIterator) HasNext() bool {
	return this.q.Size() != 0
}

