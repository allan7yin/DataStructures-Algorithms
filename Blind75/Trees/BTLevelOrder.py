from collections import deque


# Definition for a binary tree node.id
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    def levelOrder(self, root: Optional[TreeNode]) -> List[List[int]]:
        if not root:
            return []
        queue = deque()
        queue.append(root)
        result = []
        while len(queue) > 0:
            row = []
            for i in range(len(queue)):
                top = queue.popleft()
                row.append(top.val)
                if top.left:
                    queue.append(top.left)
                if top.right:
                    queue.append(top.right)
            result.append(row)

        return result
