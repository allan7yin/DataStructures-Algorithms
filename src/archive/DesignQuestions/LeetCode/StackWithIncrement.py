class CustomStack:

    def __init__(self, maxSize: int):
        self.capacity = maxSize
        self.adjustement = [0] * maxSize
        self.stack = []

    def push(self, x: int) -> None:
        if len(self.stack) < self.capacity:
            self.stack.append(x)

    def pop(self) -> int:
        result = -1
        if len(self.stack) > 0:
            index = len(self.stack) - 1
            result = self.stack.pop() + self.adjustement[index]
            self.adjustement[index] = 0

        return result

    def increment(self, k: int, val: int) -> None:
        size = min(k, len(self.stack))
        for i in range(size):
            self.adjustement[i] += val


# Your CustomStack object will be instantiated and called as such:
# obj = CustomStack(maxSize)
# obj.push(x)
# param_2 = obj.pop()
# obj.increment(k,val)
