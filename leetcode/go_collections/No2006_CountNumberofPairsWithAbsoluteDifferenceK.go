package lc2006

func countKDifference(nums []int, k int) int {

	var retCnt int = 0
	cnter := make(map[int]int, 0)
	for _, v := range nums {
		retCnt += cnter[v-k]
		retCnt += cnter[v+k]
		cnter[v]++
	}

	return retCnt
}
