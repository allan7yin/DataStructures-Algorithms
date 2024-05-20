class TwoSum:
    """
    @param number: An integer
    @return: nothing
    """

    def __init__(self):
        self.numbers = []

    def add(self, number):
        self.numbers.append(number)

    """
    @param value: An integer
    @return: Find if there exists any pair of numbers which sum is equal to the value.
    """

    def find(self, value):
        want = set()
        for num in self.numbers:
            if num in want:
                return True
            want.add(value - num)
        return False
