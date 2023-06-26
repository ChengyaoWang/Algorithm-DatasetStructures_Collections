package lc686

import "strings"

func repeatedStringMatch(a string, b string) int {

	lo, hi := 1, len(b)/len(a)+3
	for lo < hi {
		mid := (lo + hi) / 2
		aa := strings.Repeat(a, mid)
		if strings.Contains(aa, b) {
			hi = mid
		} else {
			lo = mid + 1
		}
	}

	if lo == len(b)/len(a)+3 {
		return -1
	}
	return lo
}
