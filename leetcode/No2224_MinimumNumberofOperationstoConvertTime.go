package lc2224

import "strconv"

func convertTime(current string, correct string) int {

	gap := parseTime(correct) - parseTime(current)
	if gap < 0 {
		gap += 2400
	}

	var minOpCnt int = 0
	for _, step := range []int{60, 15, 5, 1} {
		for gap >= step {
			gap -= step
			minOpCnt += 1
		}
	}

	return minOpCnt
}

func parseTime(time string) int {
	h, _ := strconv.Atoi(time[:2])
	m, _ := strconv.Atoi(time[3:])
	return 60*h + m
}
