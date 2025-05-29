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
    vector<int> rightSideView(TreeNode *root) {
        if (!root) return {};
        vector<int> view;
        deque<TreeNode *> frontier;
        frontier.push_back(root);

        while (!frontier.empty()) {
            view.push_back(frontier.back()->val);
            int size = frontier.size();
            for (int i = 0; i < size; i++) {
                if (frontier.front()->left) frontier.push_back(frontier.front()->left);
                if (frontier.front()->right) frontier.push_back(frontier.front()->right);
                frontier.pop_front();
            }
        }

        return view;
    }
};