"""
Problem Description:
--------------------
We want to design a data structure that supports `insert`, `delete`, and `get_random`
operations, all in constant time. In this case, constant time insertion and
deletion always means some hashmap.

In this example, we don't really have any need for the hashmap's values, so we'll
just use some dummy data
"""

from collections import defaultdict
import random


class DataStructure:
    def __init__(self):
        self.map = defaultdict(int)
        self.keys = set()

    def insert(self, key):
        self.map[key] += 1
        self.keys.add(key)

    def delete(self, key) -> bool:
        if key not in self.map:
            return False

        self.map[key] -= 1
        if self.map[key] == 0:
            self.map.pop(key)
            self.keys.remove(key)

        return True

    def get_random(self):
        idx = random.randint(
            0,
        )
