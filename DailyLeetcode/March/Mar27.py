from typing import List

"""
The important thing to note here is line `count += (r - l + 1)`
Consider the list 1 2 3 4 5 with k = 7.
    - Say we have already iterated through 1 and 2
    - moving r to 3, means we are now looking at subarray [1,2,3]
    - so, adding the 3 into this means we introduced 3 new sub arrays
        - 123, 23, 3
    - hence why we add (r-l+1) to count
"""

class Solution:
    def numSubarrayProductLessThanK(self, nums: List[int], k: int) -> int:
        product = 1
        count = 0
        l = 0
        for r in range(len(nums)):
            product *= nums[r]
            while l <= r and product >= k:
                product /= nums[l]
                l += 1
            count += (r - l + 1)
        return count
            

