"""
The key is to use a delimiter -- to ensure that we know where to stop

size | # | word
"""


class Solution:
    """
    @param: strs: a list of strings
    @return: encodes a list of strings to a single string.
    """

    def encode(self, strs):
        encrypted = ""
        for word in strs:
            size = str(len(word))
            encrypted += size + "#" + word
        return encrypted

    """
    @param: str: A string
    @return: decodes a single string to a list of strings
    """

    def decode(self, str):
        result = []
        i = 0
        while i < len(str):
            size = 0
            while i < len(str) and str[i] >= "0" and str[i] <= "9":
                # it is a digit, add it to the current count
                digit = int(str[i])
                size *= 10
                size += digit
                i += 1

            # now, i == #, so next ones, we will start reading the string
            i += 1
            word = ""
            for _ in range(size):
                word += str[i]
                i += 1
            result.append(word)

        return result
