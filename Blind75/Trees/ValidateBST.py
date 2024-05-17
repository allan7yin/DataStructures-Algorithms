# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def isValidBST(self, root: Optional[TreeNode]) -> bool:
        def dfs(root, maxLeft, minRight):
            if not root:
                return True
            if not (root.val > maxLeft and root.val < minRight):
                return False

            return dfs(root.left, maxLeft, root.val) and dfs(
                root.right, root.val, minRight
            )

        return dfs(root, float("-inf"), float("inf"))
