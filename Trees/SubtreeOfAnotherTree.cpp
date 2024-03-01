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
  bool isSubtree(TreeNode *root, TreeNode *subRoot) {
    if (root == nullptr) {
      return false;
    }
    if (subRoot == nullptr) {
      return true;
    }
    if (root->val == subRoot->val) {
      if (compare(root, subRoot)) {
        return true;
      }
    }
    return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
  }

  bool compare(TreeNode *root, TreeNode *subRoot) {
    // this helper function makes the assumption that root->val and subRoot->val
    // are same
    if (root == nullptr && subRoot == nullptr) {
      return true;
    } else if (root == nullptr || subRoot == nullptr) {
      return false;
    }
    if (root->val != subRoot->val) {
      return false;
    } else {
      return compare(root->left, subRoot->left) &&
             compare(root->right, subRoot->right);
    }
  }
};
