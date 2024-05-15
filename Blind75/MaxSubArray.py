from typing import List


class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        dp = [0] * len(nums)
        dp[0] = nums[0]
        maxValue = nums[0]

        for i in range(1, len(nums)):
            dp[i] = nums[i] + max(0, dp[i - 1])
            maxValue = max(maxValue, dp[i])

        return maxValue
