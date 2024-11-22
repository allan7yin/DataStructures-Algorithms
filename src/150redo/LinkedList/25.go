package LinkedList

/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func reverseKGroup(head *ListNode, k int) *ListNode {
	count := 0
	current := head
	var prev *ListNode = nil
	left := head

	for current != nil {
		count++
		if count == k {
			nextBlock := current.Next
			node := reverseBlock(left, current)

			if prev != nil {
				prev.Next = node
			} else {
				head = node
			}

			left.Next = nextBlock
			prev = left
			left = nextBlock
			count = 0
			current = nextBlock
			continue
		}

		current = current.Next
	}

	return head
}

func reverseBlock(start *ListNode, end *ListNode) *ListNode {
	var prev *ListNode = nil
	current := start
	next := end.Next
	for current != next {
		temp := current.Next
		current.Next = prev
		prev = current
		current = temp
	}

	return prev
}
