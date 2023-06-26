package lc739

type stack []int

func (s stack) Empty() bool {
	return len(s) == 0
}
func (s *stack) Push(i int) {
	*s = append(*s, i)
}
func (s *stack) Pop() int {
	n := len(*s)
	elem := (*s)[n-1]
	(*s) = (*s)[:n-1]
	return elem
}
func (s *stack) Back() int {
	n := len(*s)
	elem := (*s)[n-1]
	return elem
}

func dailyTemperatures(temperatures []int) []int {

	ret := make([]int, len(temperatures))
	s := stack{}
	for i, t := range temperatures {
		for !s.Empty() && temperatures[s.Back()] < t {
			elem := s.Pop()
			ret[elem] = i - elem
		}
		s.Push(i)
	}
	return ret
}
