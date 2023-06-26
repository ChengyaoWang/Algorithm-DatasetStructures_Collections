package lc2108

func isPalindrome(s *string) bool {
	lo, hi := 0, len(*s)-1

	for lo < hi {
		if (*s)[lo] != (*s)[hi] {
			return false
		}
		lo += 1
		hi -= 1
	}

	return true
}

func firstPalindrome(words []string) string {

	for _, s := range words {
		if isPalindrome(&s) {
			return s
		}
	}

	return ""
}
