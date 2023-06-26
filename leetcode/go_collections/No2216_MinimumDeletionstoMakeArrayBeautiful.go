package lc2216

func minDeletion(nums []int) int {

	delSoFar := 0
	realIdx, prevElem := 0, -1
	for _, elem := range nums {

		if realIdx&1 == 1 && elem == prevElem {
			delSoFar += 1
		} else {
			realIdx += 1
			prevElem = elem
		}
	}

	if (len(nums)-delSoFar)&1 == 1 {
		delSoFar += 1
	}

	return delSoFar
}
