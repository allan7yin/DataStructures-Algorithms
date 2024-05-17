from typing import List


class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        nums.sort()
        result = []

        for i, num in enumerate(nums):
            if num > 0:
                break
            if i > 0 and num == nums[i - 1]:
                continue

            target = 0 - num
            l = i + 1
            mySet = set()
            added = set()
            while l < len(nums):
                if nums[l] in mySet:
                    if (num, nums[l], target - nums[l]) not in added:
                        result.append([num, nums[l], target - nums[l]])
                        added.add((num, nums[l], target - nums[l]))
                mySet.add(target - nums[l])
                l += 1

        return result
