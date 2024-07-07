
// Definition for a binary tree node.
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// reverse in order traversal: right, curr, left: key is to maintain a moving sum
class Solution {
public:
  TreeNode *bstToGst(TreeNode *root) {
    int sum = 0;
    reverse_order_traversal(root, sum);
    return root;
  }

  void reverse_order_traversal(TreeNode *root, int &sum) {
    if (!root)
      return;
    reverse_order_traversal(root->right, sum);
    sum += root->val;
    root->val = sum;
    reverse_order_traversal(root->left, sum);
  }
};