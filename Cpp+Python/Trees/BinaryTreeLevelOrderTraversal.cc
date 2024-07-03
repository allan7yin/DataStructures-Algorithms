#include <queue>
#include <vector>
using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};

// Perform basic BFS
class Solution {
public:
  vector<vector<int>> levelOrder(TreeNode *root) {
    vector<vector<int>> result;
    queue<TreeNode *> q;
    q.push(root);
    while (!q.empty()) {
      vector<int> row;
      int n = q.size();
      for (int i = 0; i < n; i++) {
        TreeNode *first = q.front();
        if (first != nullptr) {
          q.push(first->left);
          q.push(first->right);
          row.push_back(first->val);
        }
        q.pop();
      }
      if (!row.empty()) {
        result.push_back(row);
      }
    }
    return result;
  }
};
