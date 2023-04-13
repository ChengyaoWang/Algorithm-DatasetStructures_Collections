package lc1408

// This Function Checks if s is a substring of t using KMP algorithm
func kmp_algo(s, t string) bool {

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
	for j < nt {
		if s[i] == t[j] {
			i += 1
			j += 1
		}
		if i == ns {
			return true
		} else if j < nt && s[i] != t[j] {
			if i != 0 {
				i = lps[i-1]
			} else {
				j += 1
			}
		}
	}
	return false
}

func stringMatching(words []string) []string {

	ret := make([]string, 0)
	for i := 0; i < len(words); i += 1 {
		for j := 0; j < len(words); j += 1 {
			if i == j {
				continue
			}
			if kmp_algo(words[i], words[j]) {
				ret = append(ret, words[i])
				break
			}
		}
	}
	return ret

}
