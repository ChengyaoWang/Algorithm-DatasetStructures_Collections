package lc2086

func minimumBuckets(hamsters string) int {
	var ret int = 0
	hamsters_arr := []byte(hamsters)

	for i, c := range hamsters_arr {
		if c == 'H' {
			if i > 0 && hamsters_arr[i-1] == '+' {
				continue
			}
			if i < len(hamsters_arr)-1 && hamsters_arr[i+1] == '.' {
				hamsters_arr[i+1] = '+'
				ret += 1
				continue
			}
			if i > 0 && hamsters_arr[i-1] == '.' {
				hamsters_arr[i-1] = '+'
				ret += 1
				continue
			}
			return -1
		}
	}

	return ret
}
