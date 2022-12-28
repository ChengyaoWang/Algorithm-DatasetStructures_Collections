package lc689

import "math"

type opt struct {
	sum, idx int
}

func maxSumOfThreeSubarrays(nums []int, k int) []int {

	// First Build Partial Sum
	subArrSum := make([]int, 0)
	var runningSum int = 0
	for i, v := range nums {
		runningSum += v
		if i >= k {
			subArrSum = append(subArrSum, runningSum)
			runningSum -= nums[i-k]
		}
	}

	// Then We Build dp arrays
	var opt_l opt = opt{math.MinInt, -1}
	var opt_r opt = opt{math.MinInt, -1}
	l, r := make([]opt, 0), make([]opt, 0)

	for i := 0; i < len(subArrSum); i++ {
		opt_l = max(opt_l, opt{subArrSum[i], i})
		l = append(l, opt_l)
	}
	for j := len(subArrSum) - 1; j >= 0; j-- {
		opt_r = max(opt_r, opt{subArrSum[j], j})
		r = append(r, opt_r)
	}

	var retAns []int
	var optSum int = math.MinInt

	for i := k; i < len(subArrSum)-k; i++ {
		if curSum := subArrSum[i] + l[i-k].sum + r[len(subArrSum)-1-(i+k)].sum; curSum > optSum {
			optSum = curSum
			retAns = []int{l[i-k].idx, i, r[len(subArrSum)-1-(i+k)].idx}
		}
	}

	return retAns
}

func max(i, j opt) opt {
	if i.sum > j.sum {
		return i
	} else if i.sum < j.sum {
		return j
	} else if i.idx < j.idx {
		return i
	}
	return j
}
