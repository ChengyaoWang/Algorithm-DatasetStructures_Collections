package lc705

type MyHashSet struct {
	m      [][]int
	MODKEY int
}

func Constructor() MyHashSet {
	return MyHashSet{
		m:      make([][]int, 1<<15),
		MODKEY: 1 << 15,
	}
}

func (this *MyHashSet) Add(key int) {
	k := key % this.MODKEY
	for _, elem := range this.m[k] {
		if elem == key {
			return
		}
	}
	this.m[k] = append(this.m[k], key)
}

func (this *MyHashSet) Remove(key int) {
	k := key % this.MODKEY
	for i, elem := range this.m[k] {
		if elem == key {
			this.m[k][0], this.m[k][i] = this.m[k][i], this.m[k][0]
			break
		}
	}

	if len(this.m[k]) > 0 && this.m[k][0] == key {
		this.m[k] = this.m[k][1:]
	}
}

func (this *MyHashSet) Contains(key int) bool {
	k := key % this.MODKEY
	for _, elem := range this.m[k] {
		if elem == key {
			return true
		}
	}
	return false
}

/**
 * Your MyHashSet object will be instantiated and called as such:
 * obj := Constructor();
 * obj.Add(key);
 * obj.Remove(key);
 * param_3 := obj.Contains(key);
 */
