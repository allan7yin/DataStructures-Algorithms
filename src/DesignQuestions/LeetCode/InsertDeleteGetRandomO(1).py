import random

"""
This is a very clever implementation:
    - we will use hashmap to keep track of inserted terms
    - map the val to the index in the array
    - upon deleting, swap with last value, and then pop last value
"""


class RandomizedSet:
    def __init__(self):
        self.hashSet = {}
        self.nums = []

    def insert(self, val: int) -> bool:
        if val in self.hashSet:
            return False

        self.nums.append(val)
        self.hashSet[val] = len(self.nums) - 1
        return True

    def remove(self, val: int) -> bool:
        if val not in self.hashSet:
            return False

        idx = self.hashSet[val]
        last_val = self.nums[-1]
        self.nums[idx] = last_val

        self.hashSet[last_val] = idx
        self.hashSet.pop(val)
        self.nums.pop()
        return True

    def getRandom(self) -> int:
        idx = random.randint(0, len(self.nums) - 1)
        return self.nums[idx]


# Your RandomizedSet object will be instantiated and called as such:
# obj = RandomizedSet()
# param_1 = obj.insert(val)
# param_2 = obj.remove(val)
# param_3 = obj.getRandom()
# Your RandomizedSet object will be instantiated and called as such:
# obj = RandomizedSet()
# param_1 = obj.insert(val)
# param_2 = obj.remove(val)
# param_3 = obj.getRandom()
