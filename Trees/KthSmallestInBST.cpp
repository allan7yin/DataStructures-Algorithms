#include <vector>
using namespace std;

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
  int kthSmallest(TreeNode *root, int k) {
    int result = 0;
    vector<int> nums;
    inOrderTraversal(root, nums, k);
    for (int i = 0; i < k; i++) {
      result = nums[i];
    }
    return result;
  }

  void inOrderTraversal(TreeNode *root, vector<int> &nums, int k) {
    if (!root) {
      return;
    }
    inOrderTraversal(root->left, nums, k);
    nums.push_back(root->val);
    if (nums.size() >= k) {
      return;
    }
    inOrderTraversal(root->right, nums, k);
  }
};
