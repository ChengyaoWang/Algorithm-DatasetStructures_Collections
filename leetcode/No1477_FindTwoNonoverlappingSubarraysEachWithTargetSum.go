package lc1477

import "math"

var maxInt int = math.MaxInt >> 3

func minSumOfLengths(arr []int, target int) int {

	var N int = len(arr)

	l, r := make(map[int]int), make(map[int]int)
	l[-1], r[len(arr)] = maxInt, maxInt

	// Fill in left
	var runningSum int = 0
	for i, j := 0, -1; i < N; i++ {
		runningSum += arr[i]

		for ; (runningSum > target) && (j < i); j++ {
			runningSum -= arr[j+1]
		}

		if runningSum == target {
			l[i] = i - j
		} else {
			l[i] = maxInt
		}

		l[i] = min(l[i], l[i-1])
	}

	// Fill in Right
	runningSum = 0
	for i, j := N-1, N; i >= 0; i-- {
		runningSum += arr[i]

		for ; (runningSum > target) && (j > i); j-- {
			runningSum -= arr[j-1]
		}

		if runningSum == target {
			r[i] = j - i
		} else {
			r[i] = maxInt
		}

		r[i] = min(r[i], r[i+1])
	}

	var optL int = maxInt
	for i := 0; i < N; i++ {
		optL = min(optL, l[i]+r[i+1])
	}

	if optL > N {
		return -1
	}
	return optL
}

func min(i, j int) int {
	if i < j {
		return i
	}
	return j
}
