/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
  public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
        if (q->val < p->val) swap(p, q);
        return f(root, p, q);
    }

    TreeNode *f(TreeNode *root, TreeNode *p, TreeNode *q) {
        if (!root) return nullptr;
        if (root->val >= p->val && root->val <= q->val) {
            return root;
        } else if (root->val > q->val) {
            return f(root->left, p, q);
        } else {
            return f(root->right, p, q);
        }
    }
};