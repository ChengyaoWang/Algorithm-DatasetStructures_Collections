package lc884

import "strings"

func uncommonFromSentences(s1 string, s2 string) []string {

	cnter := make(map[string]int, 0)

	for _, s := range strings.Split(s1, " ") {
		cnter[s] += 1
	}

	for _, s := range strings.Split(s2, " ") {
		cnter[s] += 1
	}

	ret := make([]string, 0)
	for s, i := range cnter {
		if i == 1 {
			ret = append(ret, s)
		}
	}

	return ret
}
