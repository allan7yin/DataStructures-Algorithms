class Vector2D(object):

    # @param vec2d {List[List[int]]}
    def __init__(self, vec2d):
        # Initialize your data structure here
        self.nums = []
        self.index = 0
        for vec in vec2d:
            for num in vec:
                self.nums.append(num)

    # @return {int} a next element
    def next(self):
        # Write your code here
        result = self.nums[self.index]
        self.index += 1
        return result

    # @return {boolean} true if it has next element
    # or false
    def hasNext(self):
        # Write your code here
        return self.index != len(self.nums)


# Your Vector2D object will be instantiated and called as such:
# i, v = Vector2D(vec2d), []
# while i.hasNext(): v.append(i.next())
