import heapq


class SeatManager:

    def __init__(self, n: int):
        self.nextAvailableSeat = []
        for i in range(1, n + 1):
            heapq.heappush(self.nextAvailableSeat, i)

    def reserve(self) -> int:
        val = heapq.heappop(self.nextAvailableSeat)
        return val

    def unreserve(self, seatNumber: int) -> None:
        heapq.heappush(self.nextAvailableSeat, seatNumber)


# Your SeatManager object will be instantiated and called as such:
# obj = SeatManager(n)
# param_1 = obj.reserve()
# obj.unreserve(seatNumber)
