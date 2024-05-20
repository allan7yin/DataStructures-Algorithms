from collections import deque

"""
2 queues ->
    - we'll push the new number into q1, which is empty, and the rest is in q1
    - then, push everything from q2 into q2, and switch their names
        - now, newly pushed element is at beginning of the queue
"""


class MyStack:
    def __init__(self):
        self.mainq = deque()
        self.secondq = deque()

    def push(self, x: int) -> None:
        self.secondq.append(x)
        while len(self.mainq) > 0:
            self.secondq.append(self.mainq.popleft())

        # switch name
        temp = self.mainq
        self.mainq = self.secondq
        self.secondq = temp

    def pop(self) -> int:
        return self.mainq.popleft()

    def top(self) -> int:
        return self.mainq[0]

    def empty(self) -> bool:
        return len(self.mainq) == 0


# Your MyStack object will be instantiated and called as such:
# obj = MyStack()
# obj.push(x)
# param_2 = obj.pop()
# param_3 = obj.top()
# param_4 = obj.empty()
