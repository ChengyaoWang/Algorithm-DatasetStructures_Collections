package lc367

func isPerfectSquare(num int) bool {
	lo, hi := 0, num+1
	for lo < hi {
		mid := (hi-lo)/2 + lo
		if mid*mid < num {
			lo = mid + 1
		} else {
			hi = mid
		}
	}

	return lo*lo == num
}
