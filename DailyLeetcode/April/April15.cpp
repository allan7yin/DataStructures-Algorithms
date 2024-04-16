
// Definition for a binary tree node.
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
  int sum = 0;

public:
  int sumNumbers(TreeNode *root) {
    dfs(root, 0);
    return sum;
  }

  void dfs(TreeNode *curr, int val) {
    if (curr == nullptr) {
      return;
    }

    // check if is leaf node
    if (!curr->left && !curr->right) {
      // add branch into sum
      sum += ((val * 10) + curr->val);
      return;
    }

    // otherwie, recurse
    dfs(curr->left, (val * 10) + curr->val);
    dfs(curr->right, (val * 10) + curr->val);
  }
};
