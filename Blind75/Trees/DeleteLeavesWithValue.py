class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    def removeLeafNodes(
        self, root: Optional[TreeNode], target: int
    ) -> Optional[TreeNode]:
        if not root:
            return None

        root.left = self.removeLeafNodes(root.left, target)
        root.right = self.removeLeafNodes(root.right, target)

        if not root.left and not root.right and root.val == target:
            return None

        return root

    # the below is first try, and too verbose
    def removeLeafNodes(
        self, root: Optional[TreeNode], target: int
    ) -> Optional[TreeNode]:
        # define side = 1 when root is left child, and 0 otherwise
        def dfs(root, parent, side):
            if not root:
                return

            # first check if leaf
            if not root.left and not root.right and root.val == target:
                if side == 1:
                    parent.left = None
                else:
                    parent.right = None
            else:
                # not leaf node, recurse onto it's children
                dfs(root.left, root, 1)
                dfs(root.right, root, 0)

            # now, after finishing recursion, this node may have become leaf, check
            if not root.left and not root.right and root.val == target:
                if side == 1:
                    parent.left = None
                else:
                    parent.right = None

        dfs(root.left, root, 1)
        dfs(root.right, root, 0)

        if not root.left and not root.right and root.val == target:
            return None
        return root
