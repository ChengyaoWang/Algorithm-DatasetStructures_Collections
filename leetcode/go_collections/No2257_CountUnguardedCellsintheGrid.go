package lc2257

type MySet struct {
	l int
	m map[int]bool
}

func (s *MySet) Contains(i, j int) bool {
	_, ok := s.m[i*s.l+j]
	if ok {
		return true
	}
	return false
}
func (s *MySet) Insert(arr ...[]int) {
	for _, elem := range arr {
		i, j := elem[0], elem[1]
		s.m[i*s.l+j] = true
	}
}
func (s MySet) Len() int {
	return len(s.m)
}

func countUnguarded(m int, n int, guards [][]int, walls [][]int) int {

	occupied := MySet{n, make(map[int]bool)}
	watched := MySet{n, make(map[int]bool)}
	occupied.Insert(guards...)
	occupied.Insert(walls...)

	dirs := [][]int{{-1, 0}, {1, 0}, {0, -1}, {0, 1}}
	inRange := func(i, j int) bool {
		return 0 <= i && i < m && 0 <= j && j < n
	}

	for _, g := range guards {
		i, j := g[0], g[1]
		for _, d := range dirs {
			di, dj := i, j
			for {
				di, dj = di+d[0], dj+d[1]
				if !inRange(di, dj) || occupied.Contains(di, dj) {
					break
				}
				watched.Insert([]int{di, dj})
			}
		}
	}

	return m*n - occupied.Len() - watched.Len()

}
