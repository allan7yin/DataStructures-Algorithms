class SmallestInfiniteSet:

    def __init__(self):
        self.smallest = 1
        self.gone = set()

    def popSmallest(self) -> int:
        while self.smallest in self.gone:
            self.smallest += 1
        result = self.smallest
        self.gone.add(result)
        self.smallest += 1
        return result

    def addBack(self, num: int) -> None:
        if num in self.gone:
            self.gone.remove(num)

        if num < self.smallest:
            self.smallest = num


# Your SmallestInfiniteSet object will be instantiated and called as such:
# obj = SmallestInfiniteSet()
# param_1 = obj.popSmallest()
# obj.addBack(num)
