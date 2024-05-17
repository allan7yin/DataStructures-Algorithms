import heapq


class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        heap = []
        for num in nums:
            heapq.heappush(heap, -num)

        result = []

        for i in range(k):
            top = heapq.heappop(heap)
            result.append(-top)

        return result
