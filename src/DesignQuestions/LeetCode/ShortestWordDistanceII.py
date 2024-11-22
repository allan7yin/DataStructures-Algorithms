from typing import List
from collections import defaultdict


class WordDistance:

    def __init__(self, wordsDict: List[str]):
        # construct hashmap from this
        self.fmap = defaultdict(list)
        for i in range(len(wordsDict)):
            self.fmap[wordsDict[i]].append(i)

    """
    @param word1: word1
    @param word2: word2
    @return: the shortest distance between two words
    """

    def shortest(self, word1: str, word2: str) -> int:
        # write your code here
        indexes1 = self.fmap[word1]
        indexes2 = self.fmap[word2]
        minDistance = sys.maxsize
        l, r = 0, 0
        m, n = len(indexes1), len(indexes2)
        while l < m and r < n:
            temp = abs(indexes1[l] - indexes2[r])
            minDistance = min(minDistance, temp)

            if indexes1[l] < indexes2[r]:
                l += 1
            else:
                r += 1
        return minDistance
