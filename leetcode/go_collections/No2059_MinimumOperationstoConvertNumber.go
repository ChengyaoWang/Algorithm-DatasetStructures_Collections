package lc2059

func minimumOperations(nums []int, start int, goal int) int {

	globalSet := make(map[int]interface{})
	currentDepth := make(map[int]interface{})
	nextDepth := make(map[int]interface{})

	unSeen_and_withinRange := func(elem int) bool {
		if elem == goal {
			return true
		}
		_, ok := globalSet[elem]
		if !ok && 0 <= elem && elem <= 1000 {
			nextDepth[elem] = true
			globalSet[elem] = true
		}
		return false
	}

	currentDepth[start] = true
	var depth int = 0
	for len(currentDepth) > 0 {
		for k, _ := range currentDepth {
			for _, n := range nums {
				if unSeen_and_withinRange(k+n) ||
					unSeen_and_withinRange(k-n) ||
					unSeen_and_withinRange(k^n) {
					return depth + 1
				}
			}
		}

		currentDepth, nextDepth = nextDepth, currentDepth
		for k := range nextDepth {
			delete(nextDepth, k)
		}
		depth += 1
	}

	return -1

}
