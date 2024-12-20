from collections import defaultdict


class UndergroundSystem:

    def __init__(self):
        self.enterLocation = {}
        self.averageTime = defaultdict(list)

    def checkIn(self, id: int, stationName: str, t: int) -> None:
        # check in the individual
        if id in self.enterLocation:
            return
        self.enterLocation[id] = (stationName, t)

    def checkOut(self, id: int, stationName: str, t: int) -> None:
        stationNameFrom, timeEntered = self.enterLocation[id]
        self.averageTime[(stationNameFrom, stationName)].append(t - timeEntered)
        self.enterLocation.pop(id)

    def getAverageTime(self, startStation: str, endStation: str) -> float:
        val = 0
        count = 0
        for interval in self.averageTime[(startStation, endStation)]:
            val += interval
            count += 1
        return val / count


# Your UndergroundSystem object will be instantiated and called as such:
# obj = UndergroundSystem()
# obj.checkIn(id,stationName,t)
# obj.checkOut(id,stationName,t)
# param_3 = obj.getAverageTime(startStation,endStation)
