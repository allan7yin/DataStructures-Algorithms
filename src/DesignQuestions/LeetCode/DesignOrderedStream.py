from typing import List


class OrderedStream:

    def __init__(self, n: int):
        self.index = 0
        self.stream = [""] * n

    def insert(self, idKey: int, value: str) -> List[str]:
        self.stream[idKey - 1] = value
        response = []

        while self.index < len(self.stream) and self.stream[self.index] != "":
            response.append(self.stream[self.index])
            self.index += 1

        return response


# Your OrderedStream object will be instantiated and called as such:
# obj = OrderedStream(n)
# param_1 = obj.insert(idKey,value)
