from collections import deque

"""
Maintain a hashmap for quick reads and use queue for deciding which 
- To be much faster, would be better to define our own linked list
"""


class LRUCache:
    def __init__(self, capacity: int):
        self.cache = {}
        self.order = deque()
        self.capacity = capacity

    def get(self, key: int) -> int:
        if key in self.cache:
            # Move the accessed key to the end of the deque
            self.order.remove(key)
            self.order.append(key)
            return self.cache[key]
        return -1

    def put(self, key: int, value: int) -> None:
        if key in self.cache:
            # Remove the key from the order deque if it already exists
            self.order.remove(key)
        elif len(self.cache) == self.capacity:
            # Evict the least recently used key
            lru = self.order.popleft()
            del self.cache[lru]

        # Add the key-value pair to the cache and mark it as recently used
        self.cache[key] = value
        self.order.append(key)


# Your LRUCache object will be instantiated and called as such:
# obj = LRUCache(capacity)
# param_1 = obj.get(key)
# obj.put(key,value)
