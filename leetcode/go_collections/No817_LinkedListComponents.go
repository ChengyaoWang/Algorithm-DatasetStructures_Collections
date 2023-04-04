package lc817

type ListNode struct {
	Val  int
	Next *ListNode
}

func numComponents(head *ListNode, nums []int) int {

	set := make(map[int]bool, 0)
	for _, elem := range nums {
		set[elem] = true
	}

	var ret int = 0
	var prev_status bool = false
	for p := head; p != nil; p = p.Next {
		if !prev_status && set[p.Val] {
			ret += 1
		}
		prev_status = set[p.Val]
	}
	return ret

}
