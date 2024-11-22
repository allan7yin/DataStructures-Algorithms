package LinkedList

func hasCycle(head *ListNode) bool {
	// refresher on the classic toirtoise and hare problem
	slow, fast := head, head

	for fast != nil && fast.Next != nil {
		slow = slow.Next
		fast = fast.Next.Next

		if slow == fast {
			return true
		}
	}
	return false
}
