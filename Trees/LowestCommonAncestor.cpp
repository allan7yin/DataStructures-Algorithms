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
  TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
    if (p->val > q->val) {
      TreeNode *temp = q;
      q = p;
      p = temp;
    }
    while (root) {
      if (root->val >= p->val && root->val <= q->val) {
        return root;
      } else if (root->val > q->val) {
        // on the left side
        root = root->left;
      } else {
        root = root->right;
      }
    }
    return root;
  }
};

int main() { return 0; }
