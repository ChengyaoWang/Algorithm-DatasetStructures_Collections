package lc1954

func minimumPerimeter(neededApples int64) int64 {

	var runningSum int64 = 0
	var i int64 = 0
	for runningSum < neededApples {
		runningSum += 12 * i * i
	}

	return 8 * i
}
