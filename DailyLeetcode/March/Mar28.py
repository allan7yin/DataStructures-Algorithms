from typing import List
from collections import defaultdict

""" Initial idea: Let's do a sliding window solution
After: I was right lol
"""
class Solution:
    def maxSubarrayLength(self, nums: List[int], k: int) -> int:
        l = 0
        maxSize = 0
        freq = defaultdict(int)

        for r, num in enumerate(nums):
            freq[num] += 1
            while freq[num] > k:
                # move the left pointer until this is no longer the case
                freq[nums[l]] -= 1
                l += 1
            
            maxSize = max(maxSize, r - l + 1)
        
        return maxSize



        