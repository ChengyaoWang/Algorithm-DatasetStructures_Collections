package lc1888

import "math"

func minFlips(s string) int {

	// Initialize
	var odd []int = []int{0, 0}
	var even []int = []int{0, 0}
	for i := 0; i < len(s); i++ {
		switch a, b := i%2 == 0, s[i] == '0'; {
		case a && b:
			even[0]++
		case a && !b:
			even[1]++
		case !a && b:
			odd[0]++
		case !a && !b:
			odd[1]++
		}
	}

	ans := min(even[1]+odd[0], even[0]+odd[1])

	if len(s)%2 == 0 {
		return ans
	}

	for i := 0; i < len(s); i++ {
		if s[i] == '0' {
			odd[0], even[0] = odd[0]+1, even[0]-1
		} else {
			odd[1], even[1] = odd[1]+1, even[1]-1
		}
		odd, even = even, odd

		ans = min(ans, even[1]+odd[0], even[0]+odd[1])
	}

	return ans

}

func min(i ...int) int {
	var ret int = math.MaxInt
	for _, v := range i {
		if v < ret {
			ret = v
		}
	}
	return ret
}
