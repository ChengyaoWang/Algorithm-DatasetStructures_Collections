package lc1024

import "sort"

func videoStitching(clips [][]int, time int) int {

	sort.Slice(clips, func(i, j int) bool {
		if clips[i][0] == clips[j][0] {
			return clips[i][1] > clips[j][1]
		}
		return clips[i][0] < clips[j][0]
	})

	var curT, maxT int = 0, -1
	var retCnt int = 0
	for _, v := range clips {
		if v[0] <= curT {
			maxT = max(maxT, v[1])
		} else if maxT < v[0] {
			return -1
		} else {
			retCnt++
			curT, maxT = maxT, -1
		}
	}

	if curT >= time {
		return retCnt + 1
	}
	return -1
}

func max(i, j int) int {
	if i > j {
		return i
	}
	return j
}
