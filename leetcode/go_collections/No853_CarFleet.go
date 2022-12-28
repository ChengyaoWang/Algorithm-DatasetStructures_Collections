package lc853

import (
	"sort"
)

type car struct {
	pos int
	t   float64
}

func carFleet(target int, position []int, speed []int) int {

	arr := make([]car, 0)

	// Joint Sort
	for i := 0; i < len(position); i++ {
		arr = append(arr, car{position[i], float64(target-position[i]) / float64(speed[i])})
	}

	sort.Slice(arr, func(i, j int) bool {
		return arr[i].pos > arr[j].pos
	})

	// Process in One Pass
	var cnt int = 1
	for i := 1; i < len(arr); i++ {
		if arr[i].t <= arr[i-1].t {
			arr[i].t = arr[i-1].t
		} else {
			cnt += 1
		}
	}

	return cnt
}
