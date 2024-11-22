package LinkedList

func reorderList(head *ListNode) {
	if head == nil || head.Next == nil {
		return
	}
	// first thing is to split this half
	slow, fast, start := head, head, head
	var prev *ListNode = nil

	for fast != nil && fast.Next != nil {
		prev = slow
		slow = slow.Next
		fast = fast.Next.Next
	}

	// wherever the left pointer is at, that is the index we cut off
	prev.Next = nil
	secondHalf := reverse(slow)

	for start != nil && secondHalf != nil {
		list1Next := start.Next
		list2Next := secondHalf.Next

		start.Next = secondHalf

		if list1Next != nil {
			secondHalf.Next = list1Next
		}

		start = list1Next
		secondHalf = list2Next
	}
}

func reverse(curr *ListNode) *ListNode {
	var prev *ListNode = nil

	for curr != nil {
		next := curr.Next
		curr.Next = prev
		prev = curr
		curr = next
	}

	return prev
}
