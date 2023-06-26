package lc726

import (
	"sort"
	"strconv"
	"unicode"
)

func isDigit(s *string) int {
	dig, err := strconv.Atoi(*s)
	if err == nil {
		return dig
	}
	return -1
}
func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

func parseFormula(formula *string, output *[]string) {

	var s string = ""

	for _, c := range *formula {

		if isDigit(&s) != -1 && unicode.IsDigit(c) {
			s += string(c)
		} else if unicode.IsLower(c) {
			s += string(c)
		} else {
			if len(s) > 0 {
				(*output) = append((*output), s)
			}
			s = string(c)
		}
	}

	if len(s) > 0 {
		(*output) = append((*output), s)
	}
}

func dfs(ptr int, parsedFormula *[]string) (int, map[string]int) {

	ret := make(map[string]int)
	bufferS := ""

	for ptr < len(*parsedFormula) {

		curS := (*parsedFormula)[ptr]
		if curS == "(" {
			ptrNext, subCnt := dfs(ptr+1, parsedFormula)
			for k, v := range subCnt {
				ret[k] += v
			}
			ptr = ptrNext
		} else if curS == ")" {
			dup := 1
			if ptr < len(*parsedFormula)-1 {
				i := isDigit(&(*parsedFormula)[ptr+1])
				if i != -1 {
					dup = i
					ptr += 1
				}
			}
			for k, _ := range ret {
				ret[k] *= dup
			}
			ptr += 1
			break
		} else {
			i := isDigit(&curS)
			if i == -1 {
				ret[curS] += 1
				bufferS = curS
			} else {
				ret[bufferS] += i - 1
			}
			ptr += 1
		}
	}

	return ptr, ret
}

func serializeOutput(cnt *map[string]int) string {
	keyList := make([]string, 0)
	for k, _ := range *cnt {
		keyList = append(keyList, k)
	}

	sort.Slice(keyList, func(i, j int) bool { return keyList[i] < keyList[j] })

	var ret string = ""
	for _, k := range keyList {
		ret += k
		if (*cnt)[k] > 1 {
			ret += strconv.Itoa((*cnt)[k])
		}
	}

	return ret
}

func countOfAtoms(formula string) string {

	parseRes := make([]string, 0)
	parseFormula(&formula, &parseRes)

	_, cnt := dfs(0, &parseRes)

	return serializeOutput(&cnt)
}
