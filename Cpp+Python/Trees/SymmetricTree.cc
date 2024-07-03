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
public:
  bool isSymmetric(TreeNode *root) { return isSame(root->left, root->right); }

  bool isSame(TreeNode *left, TreeNode *right) {
    if (left == nullptr && right == nullptr) {
      return true;
    } else if (left == nullptr || right == nullptr) {
      return false;
    }

    return (left->val == right->val && isSame(left->left, right->right) &&
            isSame(left->right, right->left));
  }
};
