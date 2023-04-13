package lc2424

type LUPrefix struct {
	n int
	g []int
}

func Constructor(n int) LUPrefix {

	arr := make([]int, n+1)
	for i, _ := range arr {
		arr[i] = -1
	}
	arr[0] = 0
	return LUPrefix{
		n: n + 1,
		g: arr,
	}
}

func (this *LUPrefix) Upload(video int) {
	(this.g)[video] = video
	if video < (this.n)-1 && (this.g)[video+1] != -1 {
		(this.g)[video] = (this.g)[video+1]
	}

	if (this.g)[video-1] != -1 {
		(this.g)[video-1] = (this.g)[video]
	}

	i := (this.g)[0]
	for i != (this.g)[i] {
		i = (this.g)[i]
	}
	(this.g)[0] = i
}

func (this *LUPrefix) Longest() int {
	return (this.g)[0]
}

/**
 * Your LUPrefix object will be instantiated and called as such:
 * obj := Constructor(n);
 * obj.Upload(video);
 * param_2 := obj.Longest();
 */
