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
            int size = q.size();
            vector<int> row;
            for (int i = 0; i < size; i++) {
                auto front = q.front();
                row.push_back(front->val);
                q.pop();
                if (front->left) q.push(front->left);
                if (front->right) q.push(front->right);
            }
            result.push_back(row);
        }

        return result;
    }
};