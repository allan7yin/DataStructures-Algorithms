from typing import List


class Solution:
    def lengthOfLIS(self, nums: List[int]) -> int:
        # brute-force O(n^2)
        n = len(nums)
        dp = [1] * n
        dp[0] = 1
        maxLen = 1
        for i in range(1, n):
            for j in range(0, i):
                if nums[j] < nums[i]:
                    dp[i] = max(dp[i], 1 + dp[j])
            maxLen = max(maxLen, dp[i])

        return maxLen
