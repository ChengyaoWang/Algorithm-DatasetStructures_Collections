package lc1438

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}
func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

type deque struct {
	arr []int
}

func (q *deque) Empty() bool {
	return len(q.arr) == 0
}
func (q *deque) Popfront() int {
	elem := q.arr[0]
	q.arr = q.arr[1:]
	return elem
}
func (q *deque) PopBack() int {
	n := len(q.arr)
	elem := q.arr[n-1]
	q.arr = q.arr[:n-1]
	return elem
}
func (q *deque) Pushback(elem int) {
	q.arr = append(q.arr, elem)
}
func (q *deque) Back() int {
	n := len(q.arr)
	return q.arr[n-1]
}
func (q *deque) Front() int {
	return q.arr[0]
}

func longestSubarray(nums []int, limit int) int {

	var ret int = 0
	lo := 0
	minQ := deque{make([]int, 0)}
	maxQ := deque{make([]int, 0)}

	for hi, elem := range nums {

		for !minQ.Empty() && nums[minQ.Back()] > elem {
			_ = minQ.PopBack()
		}
		for !maxQ.Empty() && nums[maxQ.Back()] < elem {
			_ = maxQ.PopBack()
		}
		minQ.Pushback(hi)
		maxQ.Pushback(hi)

		for nums[maxQ.Front()]-nums[minQ.Front()] > limit {
			lo += 1
			if lo > maxQ.Front() {
				maxQ.Popfront()
			}
			if lo > minQ.Front() {
				minQ.Popfront()
			}
		}
		ret = max(ret, hi-lo+1)
	}

	return ret
}
