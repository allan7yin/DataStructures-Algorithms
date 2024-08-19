#include <algorithm>
#include <climits>
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
    int maxSum = INT_MIN;

  public:
    // first try a naive recursive solution, 2 options, it either goes through the current node as a parent node, or not

    int maxPathSum(TreeNode *root) {
        f(root);
        return maxSum;
    }

    int f(TreeNode *root) {
        if (!root) return 0;

        int left = max(0, f(root->left));
        int right = max(0, f(root->right));
        int currentSum = root->val + left + right;
        maxSum = max(currentSum, maxSum);

        return root->val + max(left, right);
    }
};