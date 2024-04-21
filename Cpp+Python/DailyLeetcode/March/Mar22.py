from typing import Optional
# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next
        
class Solution:
    def isPalindrome(self, head: Optional[ListNode]) -> bool:
        # reverse the second half, firsy use tortoise and hare to find midpoint
        # while iterating, reverse the linked list
        t, h = head, head
        prev = None
        while h and h.next:
            h = h.next.next
            temp = t.next
            t.next = prev
            prev = t
            t = temp 

        if h:
            t = t.next
            # means h is 
        while prev and t:
            if (prev.val != t.val):
                return False
            prev = prev.next
            t = t.next
        return True



        