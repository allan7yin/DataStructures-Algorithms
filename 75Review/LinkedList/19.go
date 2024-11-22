package LinkedList

// time complexity => linear time O(n)
func removeNthFromEnd(head *ListNode, n int) *ListNode {
	count := 0
	prev, curr := head, head

	for curr != nil {
		if count >= n+1 {
			prev = prev.Next
		}
		curr = curr.Next
		count++
	}

	if count == n {
		return head.Next
	}
	prev.Next = prev.Next.Next
	return head
}
