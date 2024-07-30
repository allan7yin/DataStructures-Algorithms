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
    vector<vector<int>> levelOrder(TreeNode *root) {
        if (!root) return {};
        vector<vector<int>> result;
        queue<TreeNode *> q;
        q.push(root);
        while (!q.empty()) {
            vector<int> row;
            int s = q.size();

            for (int i = 0; i < s; i++) {
                auto f = q.front();
                row.push_back(f->val);
                if (f->left) q.push(f->left);
                if (f->right) q.push(f->right);
                q.pop();
            }
            result.push_back(row);
        }
        return result;
    }
};