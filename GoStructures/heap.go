package heap

import "fmt"

type Heap struct {
	arr    []int
	lambda func(int, int) bool
}

func main() {
	q := Heap{
		make([]int, 0),
		// Making it a Max Heap
		func(i, j int) bool { return i > j },
	}

	rua := []int{2, 3, 5, 4, 2, 3, 4, 5, 7}

	for _, v := range rua {
		q.Push(v)
	}
	for q.Size() > 0 {
		fmt.Println(q.Pop())
	}

}

func (q Heap) Size() int {
	return len(q.arr)
}
func (q Heap) Top() int {
	return q.arr[0]
}

func (q *Heap) Push(key int) {
	q.arr = append(q.arr, key)

	for i := len(q.arr) - 1; i != 0; {
		par := (i - 1) / 2
		if q.lambda(q.arr[i], q.arr[par]) {
			break
		}
		q.arr[i], q.arr[par] = q.arr[par], q.arr[i]
		i = par
	}
}

func (q *Heap) Pop() int {
	retElem := q.arr[0]

	q.arr[0] = q.arr[len(q.arr)-1]
	q.arr = q.arr[:len(q.arr)-1]

	for i := 0; i < len(q.arr); {
		l, r, tmp := 2*i+1, 2*i+2, i

		gL := l >= q.Size() || q.lambda(q.arr[l], q.arr[i])
		gR := r >= q.Size() || q.lambda(q.arr[r], q.arr[i])

		if gL && gR {
			break
		} else if gR || q.lambda(q.arr[r], q.arr[l]) {
			tmp = l
		} else {
			tmp = r
		}

		q.arr[i], q.arr[tmp] = q.arr[tmp], q.arr[i]
		i = tmp
	}
	return retElem
}
