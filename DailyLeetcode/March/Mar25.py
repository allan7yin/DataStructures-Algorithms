from typing import List
class Solution:
    def findDuplicates(self, nums: List[int]) -> List[int]:
        results = []
        for num in nums:

            if nums[abs(num)-1] < 0:
                # - means it was seen before
                results.append(abs(num))
            else:
                nums[abs(num)-1] *= (-1)
        return results
        