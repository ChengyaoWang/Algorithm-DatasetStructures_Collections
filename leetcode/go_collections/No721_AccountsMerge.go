package lc721

import "sort"

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

func accountsMerge(accounts [][]string) [][]string {

	unionSet := make([]int, len(accounts))
	email2usr := make(map[string]int)
	for i, _ := range unionSet {
		unionSet[i] = i
	}

	unionFind := func(i int) int {
		for i != unionSet[i] {
			i = unionSet[i]
		}
		return i
	}

	for i, info := range accounts {
		for _, email := range info[1:] {
			if j, ok := email2usr[email]; ok && i != j {
				i_par := unionFind(i)
				j_par := unionFind(j)
				min_u := min(i_par, j_par)
				unionSet[i_par] = min_u
				unionSet[j_par] = min_u
				unionSet[i] = min_u
				unionSet[j] = min_u
			} else {
				email2usr[email] = i
			}
		}
	}

	// Inverse Traverse
	ret := make([][]string, 0)
	for i := len(accounts) - 1; i >= 0; i -= 1 {
		info := accounts[i]
		if unionSet[i] == i {
			inpList := make([]string, 0)
			inpList = append(inpList, info[0])
			set := make(map[string]interface{})
			for _, email := range info[1:] {
				set[email] = true
			}
			sortList := make([]string, 0)
			for k, _ := range set {
				sortList = append(sortList, k)
			}
			sort.Slice(sortList, func(i, j int) bool { return sortList[i] < sortList[j] })
			inpList = append(inpList, sortList...)
			ret = append(ret, inpList)
		} else {
			par := unionSet[i]
			accounts[par] = append(accounts[par], info[1:]...)
		}
	}

	return ret
}
