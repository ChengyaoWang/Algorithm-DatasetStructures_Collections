package lc301

func tbd(s string) (int, int) {
	l, r := 0, 0
	for _, c := range s {
		if c == '(' {
			l += 1
		} else if c == ')' {
			if l == 0 {
				r += 1
			} else {
				l -= 1
			}
		}
	}
	return l, r
}

func isValid(s string) bool {
	lc := 0
	for _, c := range s {
		if c == '(' {
			lc += 1
		} else if c == ')' {
			if lc == 0 {
				return false
			}
			lc -= 1
		}
	}
	return lc == 0
}

func dfs(l, r, s int, sTmp string, set *map[string]bool) {

	if l == 0 && r == 0 {
		if isValid(sTmp) {
			(*set)[sTmp] = true
		}
		return
	}

	for i, c := range sTmp {
		if i < s {
			continue
		}
		if l > 0 && c == '(' {
			dfs(l-1, r, i, sTmp[:i]+sTmp[i+1:], set)
		}
		if r > 0 && c == ')' {
			dfs(l, r-1, i, sTmp[:i]+sTmp[i+1:], set)
		}
	}
	return
}

func removeInvalidParentheses(s string) []string {
	l, r := tbd(s)
	set := make(map[string]bool)
	dfs(l, r, 0, s, &set)

	ret := make([]string, 0)
	for k, _ := range set {
		ret = append(ret, k)
	}

	return ret
}
