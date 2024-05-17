class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:
        seen = set(nums)
        maxLength = 0
        for num in nums:
            currentLength = 1
            if num + 1 not in seen:
                temp = num - 1
                while temp in seen:
                    currentLength += 1
                    temp -= 1
                maxLength = max(maxLength, currentLength)

        return maxLength
