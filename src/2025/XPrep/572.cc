/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
  public:
    bool isSubtree(TreeNode *root, TreeNode *subRoot) {
        if (!root) return false;
        if (isSame(root, subRoot)) {
            return true;
        }
        return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
    }

    bool isSame(TreeNode *root, TreeNode *root2) {
        if (!root && !root2) return true;
        if (!root || !root2) return false;
        return root->val == root2->val && isSame(root->left, root2->left) && isSame(root->right, root2->right);
    }
};