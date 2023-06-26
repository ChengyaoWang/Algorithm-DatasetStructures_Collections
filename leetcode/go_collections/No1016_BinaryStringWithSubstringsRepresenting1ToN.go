package lc1016

import (
	"strconv"
	"strings"
)

func queryString(s string, n int) bool {

	for i := 1; i <= n; i += 1 {
		bin := strconv.FormatInt(int64(i), 2)
		if !strings.Contains(s, bin) {
			return false
		}
	}

	return true
}
