package lc1689

func minPartitions(n string) int {

	var retMax int = -int(^uint(0)>>1) - 1

	for _, v := range n {
		retMax = max(retMax, int(v-'0'))
	}

	return retMax
}

func max(i, j int) int {
	if i > j {
		return i
	}
	return j
}
