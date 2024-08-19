#include <unordered_map>
#include <vector>

using namespace std;

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
    unordered_map<int, int> mp;

  public:
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        for (int i = 0; i < inorder.size(); i++) {
            mp[inorder[i]] = i;
        }
        return f(preorder, inorder, 0, preorder.size() - 1, 0, inorder.size() - 1);
    }

    TreeNode *f(vector<int> &pre, vector<int> &in, int pre_s, int pre_e, int in_s, int in_e) {
        if (pre_s > pre_e || in_s > in_e) return nullptr;
        // root is the first element in preorder
        TreeNode *root = new TreeNode(pre[pre_s]);
        int i = mp[root->val];
        int leftSize = i - in_s;
        root->left = f(pre, in, pre_s + 1, pre_s + leftSize, in_s, i - 1);
        root->right = f(pre, in, pre_s + leftSize + 1, pre_e, i + 1, in_e);

        return root;
    }
};