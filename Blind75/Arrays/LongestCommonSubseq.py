"""
    a   c   e   ?
a    
b
c
d
e
?
"""


class Solution:
    def longestCommonSubsequence(self, text1: str, text2: str) -> int:
        n = len(text1)
        m = len(text2)
        dp = [[0] * (m + 1) for _ in range(n + 1)]

        for i in range(n - 1, -1, -1):
            for j in range(m - 1, -1, -1):
                if text1[i] == text2[j]:
                    dp[i][j] = 1 + dp[i + 1][j + 1]
                else:
                    # we do this, since if the current 2 characters do not match
                    # (by the way we have constructed this dp, this means 2 first characters of subsequence to not match),
                    # then, this means the longest common subsequence must be either start from the next
                    # char of text1 or the next char of text2
                    dp[i][j] = max(dp[i + 1][j], dp[i][j + 1])
        return dp[0][0]
