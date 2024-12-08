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
    vector<vector<int>> zigzagLevelOrder(TreeNode *root) {
        if (!root) {
            return {};
        }
        deque<TreeNode *> q;
        vector<vector<int>> result;
        bool left = true;
        q.push_back(root);

        while (!q.empty()) {
            vector<int> row;
            int size = q.size();

            for (int i = 0; i < size; i++) {
                TreeNode *node;
                if (left) {
                    node = q.front();
                    q.pop_front();
                } else {
                    node = q.back();
                    q.pop_back();
                }

                if (left) {
                    if (node->left) q.push_back(node->left);
                    if (node->right) q.push_back(node->right);
                } else {
                    if (node->right) q.push_front(node->right);
                    if (node->left) q.push_front(node->left);
                }

                row.push_back(node->val);
            }

            left = !left;
            result.push_back(row);
        }

        return result;
    }
};