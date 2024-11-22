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
  int rangeSumBST(TreeNode *root, int low, int high) {
    int sum = dfs(root, low, high);
    return sum;
  }

  int dfs(TreeNode *curr, int low, int high) {
    if (!curr) {
      return 0;
    }
    int result = 0;
    if (curr->val <= high && curr->val >= low) {
      result += curr->val;
      result += dfs(curr->left, low, high) + dfs(curr->right, low, high);
    }
    return result;
  }
};