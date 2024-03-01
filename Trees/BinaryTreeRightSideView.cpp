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

class Solution {
public:
  vector<int> rightSideView(TreeNode *root) {
    queue<TreeNode *> q;
    q.push(root);
    vector<int> result;

    if (!root) {
      return result;
    }

    while (!q.empty()) {
      result.push_back(q.front()->val);
      int n = q.size();
      for (int i = 0; i < n; i++) {
        TreeNode *curr = q.front();
        if (curr->right) {
          q.push(curr->right);
        }
        if (curr->left) {
          q.push(curr->left);
        }
        q.pop();
      }
    }
    return result;
  }
};
