#include <string>
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

/*
 * This is a DFS problem. We recurse, returning the string from children nodes
 * That results in the smallest string
 *
 */
class Solution {
  string result = "";

public:
  string smallestFromLeaf(TreeNode *root) {
    dfs(root, "");
    return result;
  }

  void dfs(TreeNode *root, string current) {
    if (!root) {
      return;
    }
    string temp = "";
    temp += ('a' + root->val);

    if (!root->left && !root->right) {
      // leaf node
      if (result == "") {
        result += (temp + current);
      } else {
        result = min(result, temp + current);
      }
    }
    dfs(root->left, temp + current);
    dfs(root->right, temp + current);
  }
};
