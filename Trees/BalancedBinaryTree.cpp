// Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    bool isBalanced(TreeNode *root)
    {
        bool cond = true;
        dfs(root, cond);
        return cond;
    }

    int dfs(TreeNode *root, bool &cond)
    {
        if (root == nullptr)
        {
            return 0;
        }

        int l = dfs(root->left, cond);
        int r = dfs(root->right, cond);

        if (abs(l - r) > 1)
        {
            cond = false;
        }
        return 1 + max(l, r);
    }
};
