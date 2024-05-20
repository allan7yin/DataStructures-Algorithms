# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

"""
What we can do is dfs, and on the way down, see if need to distribute coins, by bringing 
current.val - 1 coins down

Once we reach the bottom, if we are carrying > 0 coins, we bring them up to be distributed
else where 
"""


class Solution:
    def distributeCoins(self, root: Optional[TreeNode]) -> int:
        # pair: [coins, number of nodes in subtree]
        self.result = 0

        def dfs(current):
            if not current:
                return [0, 0]

            leftCoins, leftCount = dfs(current.left)
            rightCoins, rightCount = dfs(current.right)

            treeSize = leftCount + rightCount + 1
            treeCoins = leftCoins + rightCoins + current.val
            self.result += abs(treeCoins - treeSize)
            return [treeCoins, treeSize]

        dfs(root)
        return self.result
