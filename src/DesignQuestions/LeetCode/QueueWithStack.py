"""
This is largely the same as the "implement a stack with queues question"
    - maintain 3 stacks, and move everything to one of them everytime we insert
      something into the datastructure

    - will need intermediary stack when moving to maintain the desired order
"""


class MyQueue:
    def __init__(self):
        self.s1 = []
        self.s2 = []

    def push(self, x: int) -> None:
        # push onto s1 and then move everything from s2 into s2, reversing order
        pipe = []
        self.s2.append(x)

        while len(self.s1) > 0:
            pipe.append(self.s1.pop())

        while len(pipe) > 0:
            self.s2.append(pipe.pop())

        temp = self.s1
        self.s1 = self.s2
        self.s2 = temp

    def pop(self) -> int:
        return self.s1.pop()

    def peek(self) -> int:
        return self.s1[-1]

    def empty(self) -> bool:
        return len(self.s1) == 0
