package lc2180

func countEven(num int) int {

	if num == 1000 {
		return 499
	}
	var ret int = num/100*50 + num/10%10*5 + num%10/2
	if (num/100+num/10%10)%2 == 1 && num%2 == 0 {
		ret -= 1
	}

	return ret
}
