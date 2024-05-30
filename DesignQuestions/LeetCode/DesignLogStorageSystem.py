from typing import List

class LogSystem:
    def __init__(self):
        self.log = []
        self.d = {'Year':4, 'Month':7, 'Day':10, 'Hour':13, 'Minute':16, 'Second':19}

    def put(self, id: int, time: str):
        self.log.append([id, time])

    def retrieve(self, start: str, end: str, g: str) -> List[int]:
        idx = self.d[g]
        return [id for id, t in self.log if start[:idx]<=t[:idx]<=end[:idx]]r, granularity: str) -> List[int]:
