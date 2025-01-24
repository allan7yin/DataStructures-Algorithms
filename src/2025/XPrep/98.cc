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
    bool isValidBST(TreeNode *root) {
        // at every recursive step, maintain a max value on left and min value on right
        if (!root) return true;
        return f(root->left, LONG_MIN, root->val) && f(root->right, root->val, LONG_MAX);
    }

    bool f(TreeNode *curr, long L, long R) {
        if (!curr) return true;
        if (!(curr->val > L && curr->val < R)) return false;
        return f(curr->left, L, curr->val) && f(curr->right, curr->val, R);
    }
};