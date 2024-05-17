from typing import List
from collections import deque


# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


class Solution:
    def mergeKLists(self, lists: List[Optional[ListNode]]) -> Optional[ListNode]:
        if len(lists) == 0:
            return None

        """
        Each list has a ListNode inside of it 
        """

        def merge(list1, list2):
            head = ListNode()
            dummy = head
            while list1 and list2:
                if list1.val < list2.val:
                    temp = list1.next
                    dummy.next = list1
                    list1 = temp
                else:
                    temp = list2.next
                    dummy.next = list2
                    list2 = temp
                dummy = dummy.next

            if list1:
                dummy.next = list1
            if list2:
                dummy.next = list2
            return head.next

        q = deque(lists)
        while len(q) > 1:
            l1 = q.popleft()
            l2 = q.popleft()
            joinedList = merge(l1, l2)
            q.append(joinedList)

        print(len(q))
        return q[0]
