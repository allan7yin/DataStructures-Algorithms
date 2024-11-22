import heapq
from collections import defaultdict
'''
Design a data structure that supports constant time operations to:
    - insert value
    - delete value
    - findMinimum value


Some notes:
    - we need minimum value in constant time, we will need a minHeap for this
    - then, to keep track of inserting and deleting, assuming itms are unique,
      we will insert into a set
'''

class SomeDataStructure:
    def __init__(self):
        self.values = []
        self.values_set = set()

    def insert(self, num):
        heapq.heappush(self.values, num)
        self.values_set.add(num)

    def delete(self, num) -> bool:
        if num in self.values_set:


