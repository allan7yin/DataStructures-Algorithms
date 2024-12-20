from collections import defaultdict
import heapq
from typing import List

"""
Remember, heaps in Python are implemented as minHeaps by default
"""


class Twitter:
    def __init__(self):
        self.tweets = defaultdict(list)
        self.connections = defaultdict(set)
        self.count = 0

    def postTweet(self, userId: int, tweetId: int) -> None:
        self.tweets[userId].append((self.count, tweetId))
        self.count -= 1

    def getNewsFeed(self, userId: int) -> List[int]:
        result = []
        heap = []
        self.connections[userId].add(userId)
        for follower in self.connections[userId]:
            for tweetItem in self.tweets[follower]:
                heapq.heappush(heap, tweetItem)

        print(len(heap))
        for _ in range(10):
            if heap:
                _, tweetId = heapq.heappop(heap)
                result.append(tweetId)

        return result

    def follow(self, followerId: int, followeeId: int) -> None:
        self.connections[followerId].add(followeeId)

    def unfollow(self, followerId: int, followeeId: int) -> None:
        if followeeId in self.connections[followerId]:
            self.connections[followerId].remove(followeeId)


# Your Twitter object will be instantiated and called as such:
# obj = Twitter()
# obj.postTweet(userId,tweetId)
# param_2 = obj.getNewsFeed(userId)
# obj.follow(followerId,followeeId)
# obj.unfollow(followerId,followeeId)
