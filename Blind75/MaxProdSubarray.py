from typing import List

"""
The point here is to remeber, we should keep track of a maxProd and minProd 
including the ith number in the list 
"""

"""
Can defintely optimize space to be constant space
"""


class Solution:
    def maxProduct(self, nums: List[int]) -> int:
        n = len(nums)
        maxDp = [0] * n
        minDp = [0] * n
        maxDp[0] = nums[0]
        minDp[0] = nums[0]
        maxVal = nums[0]

        for i in range(1, n):
            # if the number nums[i] is negative, we multiply it by min val
            if nums[i] == 0:
                maxDp[i] = 0
                minDp[i] = 0
            elif nums[i] < 0:
                maxDp[i] = max(nums[i] * minDp[i - 1], nums[i])
                minDp[i] = min(nums[i], nums[i] * maxDp[i - 1])
            else:
                maxDp[i] = max(nums[i] * maxDp[i - 1], nums[i])
                minDp[i] = min(nums[i], nums[i] * minDp[i - 1])

            maxVal = max(maxVal, maxDp[i])
        return maxVal
