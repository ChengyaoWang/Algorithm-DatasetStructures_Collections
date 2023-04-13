package algo_pack_go

// This Function Checks if s is a substring of t using KMP algorithm
func kmp_algo(s, t string) []int {

	ns, nt := len(s), len(t)
	// Compute LPS Array (Preprocess Step)
	lps := make([]int, 1)
	di, i := 0, 1
	for i < ns {
		if s[di] == s[i] {
			di += 1
			lps = append(lps, di)
			i += 1
		} else if di != 0 {
			di = lps[di-1]
		} else {
			lps = append(lps, di)
			i += 1
		}
	}

	i, j := 0, 0
	ret := make([]int, 0)
	for j < nt {
		if s[i] == t[j] {
			i += 1
			j += 1
		}
		if i == ns {
			ret = append(ret, j-i)
			i = lps[i-1]
		} else if j < nt && s[i] != t[j] {
			if i != 0 {
				i = lps[i-1]
			} else {
				j += 1
			}
		}
	}
	return ret
}
