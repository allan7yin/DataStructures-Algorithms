/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// time: O(logn)
class Solution {
  public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
        if (p->val > q->val) swap(p, q);
        return lca(root, p, q);
    }

    TreeNode *lca(TreeNode *root, TreeNode *p, TreeNode *q) {
        if (!root) return root;
        if (root->val >= p->val && root->val <= q->val) {
            return root;
        } else if (root->val >= q->val) {
            return lca(root->left, p, q);
        }
        return lca(root->right, p, q);
    }
};