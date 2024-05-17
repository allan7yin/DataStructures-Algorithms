from collections import defaultdict
from typing import List

"""
Given an array of strings strs, group the anagrams together. You can return the answer in any order.

An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, 
typically using all the original letters exactly once.

"""


class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        result = []
        anagrams = defaultdict(list)
        for st in strs:
            wordCount = [0] * 26
            for ch in st:
                wordCount[ord(ch) - ord("a")] += 1

            key = tuple(wordCount)
            anagrams[key].append(st)

        for key in anagrams.keys():
            result.append(anagrams[key])

        return result
