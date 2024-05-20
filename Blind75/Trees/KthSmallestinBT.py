# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def kthSmallest(self, root: Optional[TreeNode], k: int) -> int:
        count, result = 0, 0

        def dfs(current):
            nonlocal count, result
            if not current:
                return

            dfs(current.left)
            count += 1
            if count == k:
                result = current.val
                return

            dfs(current.right)

        dfs(root)
        return result
