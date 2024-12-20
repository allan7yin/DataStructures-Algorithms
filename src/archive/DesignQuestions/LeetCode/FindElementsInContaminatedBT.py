from typing import Optional


# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class FindElements:
    def __init__(self, root: Optional[TreeNode]):
        self.root = root
        self.visited = set([0])
        self.recover(root)

    def recover(self, root):
        root.val = 0

        def dfs(current, val):
            if not current:
                return

            current.val = val
            self.visited.add(current.val)

            # determine the values for the children nodes here
            leftVal = (2 * val) + 1
            rightVal = (2 * val) + 2
            dfs(current.left, leftVal)
            dfs(current.right, rightVal)

        dfs(root.left, 1)
        dfs(root.right, 2)

    def find(self, target: int) -> bool:
        if target in self.visited:
            return True
        return False
