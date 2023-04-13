package lc332

import "sort"

type stack struct {
	Arr []string
}

func (s *stack) Top() string {
	n := len((*s).Arr)
	return (*s).Arr[n-1]
}
func (s *stack) Pop() string {
	n := len((*s).Arr)
	elem := (*s).Arr[n-1]
	(*s).Arr = ((*s).Arr)[:n-1]
	return elem
}
func (s stack) Size() int {
	return len(s.Arr)
}
func (s *stack) Push(elem string) {
	(*s).Arr = append((*s).Arr, elem)
}

func findItinerary(tickets [][]string) []string {
	m := make(map[string][]string, 0)
	for _, pair := range tickets {
		m[pair[0]] = append(m[pair[0]], pair[1])
	}
	for k, _ := range m {
		sort.Strings(m[k])
	}

	ret := make([]string, 0)
	revStack := stack{
		Arr: []string{"JFK"},
	}

	for revStack.Size() > 0 {
		for len(m[revStack.Top()]) > 0 {
			// n := len(m[revStack.Top()])
			elem := m[revStack.Top()][0]
			m[revStack.Top()] = m[revStack.Top()][1:]
			revStack.Push(elem)
		}
		ret = append(ret, revStack.Pop())
	}
	sort.SliceStable(ret, func(i, j int) bool {
		return i > j
	})
	return ret
}
