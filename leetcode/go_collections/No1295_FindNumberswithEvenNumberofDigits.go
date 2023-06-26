package lc1295

func findNumbers(nums []int) int {
	var ret int = 0
	for _, num := range nums {

		if 100000 <= num && num < 1000000 {
			ret += 1
		} else if 1000 <= num && num < 10000 {
			ret += 1
		} else if 10 <= num && num < 100 {
			ret += 1
		}
	}
	return ret
}
