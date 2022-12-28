type coord struct {
	i, j, d int
}

type Stack struct {
	arr []coord
}

func (q *Stack) Push(c coord) {
	q.arr = append(q.arr, c)
}
func (q *Stack) Pop() coord {
	elem := q.arr[0]
	q.arr = q.arr[1:]
	return elem
}
func (q *Stack) Empty() bool {
	return len(q.arr) == 0
}

var m, n int
var inDegree [][]int
var dir = [][]int{{-1, 0}, {1, 0}, {0, -1}, {0, 1}}

func longestIncreasingPath(matrix [][]int) int {
	// Initialization
	m, n = len(matrix), len(matrix[0])
	inDegree = make([][]int, m)
	q := Stack{make([]coord, 0)}
	for i := 0; i < m; i++ {
		inDegree[i] = make([]int, n)
	}
	for i := 0; i < m; i++ {
		for j := 0; j < n; j++ {
			for _, d := range dir {
				if inBoundary(i+d[0], j+d[1]) && matrix[i][j] > matrix[i+d[0]][j+d[1]] {
					inDegree[i][j] += 1
				}
			}
			if inDegree[i][j] == 0 {
				q.Push(coord{i, j, 1})
			}
		}
	}
	// Begin BFS
	var tmp coord
	var retDepth, i, j int
	for !q.Empty() {
		tmp = q.Pop()
		retDepth = max(tmp.d, retDepth)
		for _, d := range dir {
			i, j = tmp.i+d[0], tmp.j+d[1]
			if inBoundary(i, j) && matrix[tmp.i][tmp.j] < matrix[i][j] {
				inDegree[i][j] -= 1
				if inDegree[i][j] == 0 {
					q.Push(coord{i, j, tmp.d + 1})
				}
			}
		}
	}
	return retDepth
}

func inBoundary(i, j int) bool {
	return i >= 0 && i < m && j >= 0 && j < n
}

func max(i, j int) int {
	if i > j {
		return i
	} else {
		return j
	}
}


