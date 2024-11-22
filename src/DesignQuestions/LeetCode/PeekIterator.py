# Below is the interface for Iterator, which is already defined for you.
#
# class Iterator:
#     def __init__(self, nums):
#         """
#         Initializes an iterator object to the beginning of a list.
#         :type nums: List[int]
#         """
#
#     def hasNext(self):
#         """
#         Returns true if the iteration has more elements.
#         :rtype: bool
#         """
#
#     def next(self):
#         """
#         Returns the next element in the iteration.
#         :rtype: int
#         """
"""
This is quite hard to realize how to do it. Had to look at video. Just keep in mind
that one way we can manipulate iterators is to sometimes moved them forwards, so that 
they're ahead of where we want to be, and then stall them when we need to by one
to counter that fast forward action
"""


class PeekingIterator:
    def __init__(self, iterator):
        """
        Initialize your data structure here.
        :type iterator: Iterator
        """
        self.iterator = iterator
        self.prev = 0
        self.peeked = False

    def peek(self):
        """
        Returns the next element in the iteration without advancing the iterator.
        :rtype: int
        """
        if not self.peeked:
            # means the iterator is not yet "one iteration ahead of us", make this the case
            self.prev = self.iterator.next()
            self.peeked = True
        return self.prev

    def next(self):
        """
        :rtype: int
        """
        if self.peeked:
            self.peeked = False
            return self.prev
        else:
            return self.iterator.next()

    def hasNext(self):
        """
        :rtype: bool
        """
        if self.peeked:
            return True
        else:
            return self.iterator.hasNext()


# Your PeekingIterator object will be instantiated and called as such:
# iter = PeekingIterator(Iterator(nums))
# while iter.hasNext():
#     val = iter.peek()   # Get the next element but not advance the iterator.
#     iter.next()         # Should return the same value as [val].
