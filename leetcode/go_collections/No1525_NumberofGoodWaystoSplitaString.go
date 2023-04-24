package lc1525

func numSplits(s string) int {

	l, r := make(map[rune]int, 0), make(map[rune]int, 0)
	for _, c := range s {
		r[c] += 1
	}

	var ret int = 0
	for _, c := range s {
		if len(l) == len(r) {
			ret += 1
		}
		l[c] += 1
		r[c] -= 1
		if r[c] == 0 {
			delete(r, c)
		}
	}

	return ret
}
