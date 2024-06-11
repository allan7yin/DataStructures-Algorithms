class Solution {
public:
  int findSecondMinimumValue(TreeNode *root) {
    if (!root)
      return -1;
    int smallestValue = root->val;
    long result = dfs(root, smallestValue);
    return result == LONG_MAX ? -1 : result;
  }

  long dfs(TreeNode *current, int currentMin) {
    if (!current)
      return LONG_MAX;
    if (current->val != currentMin) {
      return current->val;
    }
    long leftResult = dfs(current->left, currentMin);
    long rightResult = dfs(current->right, currentMin);
    return min(leftResult, rightResult);
  }
};
