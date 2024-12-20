"""
Tries are very useful anytime we want to compare prefix in logn log(n)

- Seems to be only used in these types of design questions
"""


class TrieNode:
    def __init__(self):
        self.children = {}
        self.wordEnd = False


class WordDictionary:
    def __init__(self):
        self.root = TrieNode()

    def addWord(self, word: str) -> None:
        current = self.root
        for ch in word:
            if ch not in current.children:
                current.children[ch] = TrieNode()
            current = current.children[ch]

        current.wordEnd = True

    def search(self, word: str) -> bool:
        current = self.root

        def dfs(current, index):
            nonlocal word
            if index == len(word):
                return current.wordEnd
            found = False
            if word[index] == ".":
                # wildcard, matches with anything, we need to go through them all
                for key in current.children.keys():
                    found = found or dfs(current.children[key], index + 1)
            else:
                if word[index] not in current.children:
                    return False
                found = found or dfs(current.children[word[index]], index + 1)

            return found

        return dfs(current, 0)
