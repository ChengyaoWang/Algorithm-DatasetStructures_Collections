package lc2285

import "sort"

func maximumImportance(n int, roads [][]int) int64 {

	arr := make([]int, n)
	for _, elem := range roads {
		arr[elem[0]] += 1
		arr[elem[1]] += 1
	}

	sort.Slice(arr, func(i, j int) bool { return arr[i] > arr[j] })

	var ret int64 = 0
	for i, elem := range arr {
		ret += int64(n-i) * int64(elem)
	}

	return ret
}
