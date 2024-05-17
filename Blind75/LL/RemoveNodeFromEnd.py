# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def removeNthFromEnd(self, head: Optional[ListNode], n: int) -> Optional[ListNode]:
        if not head.next:
            return None
        delay = 0
        first, second, prev = head, head, None

        while first:
            prev = second
            if delay >= n:
                second = second.next
            first = first.next
            delay += 1

        if n == delay:
            # means we need to remove first one
            head = head.next
        else:
            # remove here
            prev.next = second.next
        return head
