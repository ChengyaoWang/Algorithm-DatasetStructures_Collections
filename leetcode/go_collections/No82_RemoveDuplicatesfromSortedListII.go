package lc82

type ListNode struct {
	Val  int
	Next *ListNode
}

func deleteDuplicates(head *ListNode) *ListNode {

	if head == nil {
		return nil
	} else if (head.Next == nil) || (head.Next.Val != head.Val) {
		head.Next = deleteDuplicates(head.Next)
		return head
	}

	var pp *ListNode = head
	for ; (pp != nil) && (pp.Val == head.Val); pp = pp.Next {
	}

	return deleteDuplicates(pp)
}
