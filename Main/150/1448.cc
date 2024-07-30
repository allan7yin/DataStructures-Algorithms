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
    int goodNodes(TreeNode *root) {
        return 1 + f(root->left, root->val) + f(root->right, root->val);
    }

    int f(TreeNode *cur, int pmax) {
        if (!cur) return 0;
        int result = 0;
        if (cur->val >= pmax) {
            pmax = cur->val;
            result++;
        }
        result += (f(cur->left, pmax) + f(cur->right, pmax));
        return result;
    }
};