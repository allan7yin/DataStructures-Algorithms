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
    int limit;

  public:
    TreeNode *sufficientSubset(TreeNode *root, int limit) {
        this->limit = limit;
        if (f(root, 0) == 0) {
            return nullptr;
        }
        return root;
    }

    int f(TreeNode *root, int sum) {
        if (!root) return 0; // handle null node
        if (!root->left && !root->right) return (sum + root->val >= limit) ? 1 : 0;
        // recurse
        int l = f(root->left, sum + root->val);
        int r = f(root->right, sum + root->val);
        if (l == 0) root->left = nullptr;
        if (r == 0) root->right = nullptr;
        return (l || r) ? 1 : 0;
    }
};