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
    TreeNode *insertIntoBST(TreeNode *root, int val) {
        if (!root) return new TreeNode(val);

        auto cpy = root;
        find(root, val, nullptr);
        return cpy;
    }

    void find(TreeNode *curr, int val, TreeNode *par) {
        if (!curr) {
            auto newNode = new TreeNode(val);
            if (val < par->val) {
                par->left = newNode;
            } else {
                par->right = newNode;
            }
            return;
        }

        if (val > curr->val) {
            find(curr->right, val, curr);
        } else {
            find(curr->left, val, curr);
        }
    }
};