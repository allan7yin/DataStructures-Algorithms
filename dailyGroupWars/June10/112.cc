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
  bool hasPathSum(TreeNode *root, int targetSum) {
    if (!root) {
      return 0;
    } else if (root->val == targetSum && !root->left && !root->right) {
      return true;
    }
    return dfs(root->left, root->val, targetSum) || dfs(root->right, root->val, targetSum);
  }

  bool dfs(TreeNode *current, int currentSum, int targetSum) {
    // check if child node
    if (!current) {
      return false;
    }
    bool cond = false;
    if (!current->left && !current->right) {
      // check if sum = path sum
      if (currentSum + current->val == targetSum) {
        cond = true;
      }
    } else {
      // not a leaf node, recurse
      cond = dfs(current->left, current->val + currentSum, targetSum) || dfs(current->right, current->val + currentSum, targetSum);
    }
    return cond;
  }
};