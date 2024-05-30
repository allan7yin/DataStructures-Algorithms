"""
This is the brute-force solution, which is bottom 7% of runtime of all submissions.

"""


class Allocator:
    def __init__(self, n: int):
        self.allocated_blocks = defaultdict(list)
        self.memory = [0] * n

    def allocate(self, size: int, mID: int) -> int:
        l = 0
        avail_size = 0
        for r in range(len(self.memory)):
            if self.memory[r] == 0:
                temp_size = r - l + 1
                if temp_size == size:
                    # we have enough, save and break
                    self.allocated_blocks[mID].append((l, r))
                    result = l
                    while l <= r:
                        self.memory[l] = 1
                        l += 1

                    return result
                avail_size += 1
            else:
                # means we don't have contiguous memory of size `size`
                l = r + 1
                avail_size = 0

        return -1

    def free(self, mID: int) -> int:
        freed = 0
        for pair in self.allocated_blocks[mID]:
            l, r = pair[0], pair[1]
            freed += r - l + 1
            while l <= r:
                self.memory[l] = 0
                l += 1

        self.allocated_blocks.pop(mID)
        return freed


# Your Allocator object will be instantiated and called as such:
# obj = Allocator(n)
# param_1 = obj.allocate(size,mID)
# param_2 = obj.free(mID)
