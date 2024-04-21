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
  int goodNodes(TreeNode *root) {
    int result = 0;
    dfs(root, root->val, result);
    return result;
  }

  void dfs(TreeNode *curr, int curMax, int &count) {
    if (!curr) {
      return;
    }
    if (curr->val >= curMax) {
      count++;
      curMax = curr->val;
    }
    dfs(curr->left, curMax, count);
    dfs(curr->right, curMax, count);
  }
};
