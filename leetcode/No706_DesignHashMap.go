type DictNode struct {
	K, V int
	Next *DictNode
}

type MyHashMap struct {
	m   int
	arr []*DictNode
}

/** Initialize your data structure here. */
func Constructor(m int) MyHashMap {
	return MyHashMap{m, make([]*DictNode, m)}
}

/** value will always be non-negative. */
func (this *MyHashMap) Put(key int, value int) {
	for p := this.arr[key%this.m]; p != nil; p = p.Next {
		if p.k == key {
			p.v = value
			return
		}
	}
	this.arr[key%this.m] = &DictNode{
		key, value, this.arr[key%this.m],
	}
}

/** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
func (this *MyHashMap) Get(key int) int {
	for p := this.arr[key%this.m]; p != nil; p = p.Next {
		if p.k == key {
			return p.v
		}
	}
	return -1
}

/** Removes the mapping of the specified value key if this map contains a mapping for the key */
func (this *MyHashMap) Remove(key int) {
	p := this.arr[key%this.m]
	if p == nil {
	} else if p.k == key {
		this.arr[key%this.m] = p.Next
	} else {
		next := p.Next
		for next != nil {
			if next.k == key {
				p.Next = next.Next
				return
			}
			p, next = next, next.Next
		}
	}
}

/**
 * Your MyHashMap object will be instantiated and called as such:
 * obj := Constructor();
 * obj.Put(key,value);
 * param_2 := obj.Get(key);
 * obj.Remove(key);
 */