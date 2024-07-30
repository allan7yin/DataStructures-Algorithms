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
    int result = 0;
    int count = 0;

  public:
    int kthSmallest(TreeNode *root, int k) {
        f(root, k);
        return result;
    }

    void f(TreeNode *root, int k) {
        if (!root) return;

        f(root->left, k);
        count++;
        if (count == k) {
            result = root->val;
        }
        f(root->right, k);
    }
};