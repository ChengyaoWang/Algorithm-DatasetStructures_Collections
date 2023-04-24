package lc2002

func checkPalin(mask int, s *string) int {
	p1, p2 := 0, len(*s)-1
	var ret int = 0
	for p1 <= p2 {
		if mask&(1<<p1) == 0 {
			p1 += 1
		} else if mask&(1<<p2) == 0 {
			p2 -= 1
		} else if (*s)[p1] != (*s)[p2] {
			return 0
		} else {
			ret += 1
			if p1 != p2 {
				ret += 1
			}
			p1 += 1
			p2 -= 1
		}
	}
	return ret
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

func maxProduct(s string) int {

	var n int = 1 << len(s)
	mem := make([]int, n)
	for i := 0; i < n; i += 1 {
		mem[i] = checkPalin(i, &s)
	}

	var ret int = 0
	for i := 1; i < n-1; i += 1 {
		for j := 1; j < n-1; j += 1 {
			if i&j != 0 {
				continue
			}
			ret = max(ret, mem[i]*mem[j])
		}
	}

	return ret
}
