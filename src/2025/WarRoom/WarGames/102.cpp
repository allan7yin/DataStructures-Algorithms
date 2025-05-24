#include "../bits/stdc++.h"
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
  public:
    vector<vector<int>> levelOrder(TreeNode *root) {
        if (!root) return {};
        vector<vector<int>> result;
        deque<TreeNode *> q;
        q.push_back(root);

        while (!q.empty()) {
            int size = q.size();
            vector<int> row;
            for (int i = 0; i < size; i++) {
                auto cur = q.front();
                if (cur->left) q.push_back(cur->left);
                if (cur->right) q.push_back(cur->right);

                row.push_back(cur->val);
                q.pop_front();
            }

            result.push_back(row);
        }

        return result;
    }
};