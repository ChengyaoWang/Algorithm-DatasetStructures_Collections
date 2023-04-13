package lc2262

func max(i, j int) int {
	if i > j {
		return i
	}
	return j
}

func appealSum(s string) int64 {

	var ret int64 = 0
	lastOccur := make([]int, 26)
	for i, _ := range lastOccur {
		lastOccur[i] = -1
	}

	for i := 0; i < len(s); i += 1 {
		lastOccur[s[i]-'a'] = max(lastOccur[s[i]-'a'], i)
		for _, v := range lastOccur {
			ret += int64(v + 1)
		}
	}

	return ret
}
