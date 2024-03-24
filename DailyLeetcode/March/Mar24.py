from ast import List

class Solution:
    def findDuplicate(self, nums: List[int]) -> int:
        slow, fast = 0,0
        while True:
            slow = nums[slow]
            fast = nums[nums[fast]]
            if slow == fast:
                break
        
        # now, move to front of list and move unil they meet
        fast = 0
        while True:
            slow = nums[slow]
            fast = nums[fast]
            if slow == fast:
                return slow

        



        