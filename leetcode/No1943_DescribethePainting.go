package lc1943

import "sort"

func splitPainting(segments [][]int) [][]int64 {

	m := make(map[int]int)
	for _, v := range segments {

		if _, ok := m[v[0]]; !ok {
			m[v[0]] = 0
		}
		m[v[0]] += v[2]
		if _, ok := m[v[1]]; !ok {
			m[v[1]] = 0
		}
		m[v[1]] -= v[2]
	}

	l := make([]int, 0)
	for k, _ := range m {
		l = append(l, k)
	}

	sort.Slice(l, func(i, j int) bool {
		return l[i] < l[j]
	})

	var retArr [][]int64 = [][]int64{}
	var val int = 0

	for i := 0; i < len(l)-1; i++ {
		val += m[l[i]]
		if val == 0 {
			continue
		}
		retArr = append(retArr, []int64{int64(l[i]), int64(l[i+1]), int64(val)})
	}

	return retArr
}
