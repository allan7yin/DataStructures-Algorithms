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
    vector<int> rightSideView(TreeNode *root) {
        if (!root) return {};
        // bfs and just add the last element of each into the return aray
        vector<int> result;
        queue<TreeNode *> q;
        q.push(root);

        while (!q.empty()) {
            int s = q.size();
            for (int i = 0; i < s; i++) {
                auto f = q.front();
                if (i == s - 1) {
                    result.push_back(f->val);
                }
                if (f->left) q.push(f->left);
                if (f->right) q.push(f->right);
                q.pop();
            }
        }
        return result;
    }
};