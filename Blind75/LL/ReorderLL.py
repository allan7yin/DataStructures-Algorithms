# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


class Solution:
    def reorderList(self, head: Optional[ListNode]) -> None:
        """
        Do not return anything, modify head in-place instead.
        """
        if not head.next:
            return

        def reverseList(head):
            prev = None
            while head:
                node = ListNode(head.val, prev)
                prev = node
                head = head.next
            return prev

        slow, fast, prev = head, head, None
        dummy = head
        while fast and fast.next:
            prev = slow
            slow = slow.next
            fast = fast.next.next
        prev.next = None  # sever the 2 halfs

        # slow is where we reverse from
        reverse = reverseList(slow)

        while dummy and reverse:
            temp1 = dummy.next
            temp2 = reverse.next

            dummy.next = reverse
            if temp1:
                reverse.next = temp1

            dummy = temp1
            reverse = temp2
