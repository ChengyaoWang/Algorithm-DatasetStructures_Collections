package lc1898

func maximumRemovals(s string, p string, removable []int) int {

	invMap := make(map[int]int)
	for i, elem := range removable {
		invMap[elem] = i
	}

	lo, hi := 0, len(removable)+1
	for lo < hi {
		mid, j := (hi+lo)/2, 0
		for i := 0; i < len(s) && j < len(p); i += 1 {
			v, ok := invMap[i]
			if (!ok || (v >= mid)) && s[i] == p[j] {
				j += 1
			}
		}
		if j == len(p) {
			lo = mid + 1
		} else {
			hi = mid
		}
	}

	return lo - 1
}
