from typing import Optional
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
        # reverse the list
        def reverseList(head):
            prev = None
            while head:
                node = ListNode(head.val, prev)
                prev = node
                head = head.next
            return prev
        
        copy = head 

        # we'll reverse the second half 
        slow, fast, prev = head, head, None
        while (fast and fast.next):
            prev = slow
            slow = slow.next
            fast = fast.next.next
        prev.next = None
        reverse = reverseList(slow)
        
        while copy and reverse:
            temp1 = copy.next
            temp2 = reverse.next

            copy.next = reverse
            if temp1:
                reverse.next = temp1

            copy = temp1
            reverse = temp2
    