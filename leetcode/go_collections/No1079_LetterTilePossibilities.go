package lc1079

func dfsHelper(cnter *map[rune]int) int {
	var sum int = 0
	for k, v := range *cnter {
		if v == 0 {
			continue
		}
		(*cnter)[k] -= 1
		sum += 1
		sum += dfsHelper(cnter)
		(*cnter)[k] += 1
	}
	return sum
}

func numTilePossibilities(tiles string) int {

	cnter := make(map[rune]int)
	for _, c := range tiles {
		cnter[c] += 1
	}

	return dfsHelper(&cnter)
}
