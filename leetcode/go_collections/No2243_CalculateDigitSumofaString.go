package lc2243

import "strconv"

func digitSum(s string, k int) string {

	var sum int = 0
	tmp := ""

	for len(s) > k {

		for i, c := range s {
			sum += int(c - '0')
			if (i+1)%k == 0 || i == len(s)-1 {
				tmp += strconv.Itoa(sum)
				sum = 0
			}
		}

		s = tmp
		tmp = ""
	}

	return s
}
