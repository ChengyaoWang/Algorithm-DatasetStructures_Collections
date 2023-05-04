package lc2565

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

func minimumScore(s string, t string) int {
	ss, st := len(s), len(t)
	r := make([]int, st)
	for i, _ := range r {
		r[i] = -1
	}
	k := st - 1
	for i := ss - 1; i >= 0 && k >= 0; i -= 1 {
		if s[i] == t[k] {
			r[k] = i
			k -= 1
		}
	}

	var ret int = k + 1
	for i, j := 0, 0; i < ss && j < st && ret > 0; i += 1 {
		if s[i] == t[j] {
			for k < st && r[k] <= i {
				k += 1
			}
			j += 1
			ret = min(ret, k-j)
		}
	}
	return ret
}
