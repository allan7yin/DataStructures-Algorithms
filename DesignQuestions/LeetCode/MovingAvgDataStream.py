from collections import deque


class MovingAverage(object):
    """
    @param: size: An integer
    """

    def __init__(self, size):
        # do intialization if necessary
        self.sum = 0
        self.size = size
        self.q = deque()

    """
    @param: val: An integer
    @return:  
    """

    def next(self, val):
        # write your code here
        self.sum += val
        self.q.append(val)

        if len(self.q) > self.size:
            self.sum -= self.q.popleft()
        return self.sum / len(self.q)


# Your MovingAverage object will be instantiated and called as such:
# obj = MovingAverage(size)
# param = obj.next(val)
