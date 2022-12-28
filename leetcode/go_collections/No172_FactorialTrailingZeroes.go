package lc172

func trailingZeroes(n int) int {

	base5_digit := make([]int, 0)

	for n > 0 {
		base5_digit = append(base5_digit, n%5)
		n /= 5
	}

	var cnt int = 0
	for i := 1; i < len(base5_digit)-1; i++ {
		cnt += base5_digit[len(base5_digit)-i] * i
	}

	return cnt
}
