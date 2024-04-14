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
    int sumOfLeftLeaves(TreeNode* root) {
        return recurse(root->left, root) + recurse(root->right, root);
    }

    int recurse(TreeNode* curr, TreeNode* parent) {
        if (!curr) {
            return 0;
        }
        if (!curr->left && !curr->right) {
            if (parent->left == curr) {
                return curr->val;
            } else {
                 return 0;
            }
        }
        return recurse(curr->left, curr) + recurse(curr->right, curr);
    }
};
