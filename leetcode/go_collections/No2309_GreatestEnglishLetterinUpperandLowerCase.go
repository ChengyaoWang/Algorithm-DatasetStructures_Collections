package lc2309

import "unicode"

func max(a, b rune) rune {
	if a > b {
		return a
	}
	return b
}

func greatestLetter(s string) string {
	mem := make(map[rune]bool, 0)
	var ret rune = -1

	for _, c := range s {
		mem[c] = true
		_, ok1 := mem[unicode.ToLower(c)]
		_, ok2 := mem[unicode.ToUpper(c)]
		if ok1 && ok2 {
			ret = max(ret, unicode.ToUpper(c))
		}

	}

	if ret == -1 {
		return ""
	}
	return string([]rune{ret})
}
