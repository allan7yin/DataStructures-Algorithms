class TopVotedCandidate:
    def __init__(self, persons: List[int], times: List[int]):
        self.winning = []
        self.times = times

        def populate_winning():
            nonlocal persons
            nonlocal times
            maxVotes = 0
            winningPerson = ""
            currentVotes = defaultdict(int)
            for i in range(len(persons)):
                currentVotes[persons[i]] += 1
                if currentVotes[persons[i]] >= maxVotes:
                    winningPerson = persons[i]
                    maxVotes = currentVotes[persons[i]]
                self.winning.append(winningPerson)

        populate_winning()

    def q(self, t: int) -> int:
        # binary search for the index of this time in times
        l, r = 0, len(self.times) - 1
        while l <= r:
            mid = (l + r) // 2
            if self.times[mid] == t:
                return self.winning[mid]
            elif self.times[mid] < t:
                l = mid + 1
            else:
                r = mid - 1

        return self.winning[l - 1] if l > 0 else self.winning[0]
