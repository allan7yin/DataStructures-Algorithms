from typing import List

class Solution:
    def firstMissingPositive(self, nums: List[int]) -> int:
        # first iteration, set the negative values to 0
        for i in range(len(nums)):
            if nums[i] < 0:
                nums[i] = 0
        
        # now, iterate and mark with negative sign to indicate that number exists
        for num in nums:
            val = abs(num)
            if val > 0 and val < len(nums) + 1:
                if nums[val-1] > 0:
                    nums[val-1] *= -1
                elif nums[val-1] == 0:
                    nums[val-1] = -1 * (len(nums) + 1)

            
        for i, num in enumerate(nums):
            if num >= 0:
                return i + 1
        
        return len(nums) + 1