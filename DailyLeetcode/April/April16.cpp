#include <queue>
#include <utility>
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
  queue<pair<TreeNode *, int>> q; // pair is, node and respective depth
public:
  TreeNode *addOneRow(TreeNode *root, int val, int depth) {
    q.push({root, 1});
    bfs(root, val, depth);
    return root;
  }

  void bfs(TreeNode *root, int val, int depth) {
    while (!q.empty()) {
      if (q.front().second == depth - 1) {
        // save left and right subtree, add the new nodes, and reattach old ones
        pair<TreeNode *, int> front = q.front();
        TreeNode *left = (front.first)->left;
        TreeNode *right = (front.first)->right;

        (front.first)->left = new TreeNode(val, left, nullptr);
        (front.first)->right = new TreeNode(val, nullptr, right);
        q.pop();
      }

      if (!q.empty() && q.front().second >= depth) {
        return;
      }

      pair<TreeNode *, int> front = q.front();
      if (front.first->left) {
        q.push({front.first->left, front.second + 1});
      }

      if (front.first->right) {
        q.push({front.first->right, front.second + 1});
      }
      q.pop();
    }
  }

  // DFS VERSION
  TreeNode *addOneRow(TreeNode *root, int val, int depth) {
    if (!root) {
      return root;
    }
    if (depth == 1) {
      return new TreeNode(val, root, nullptr);
    }

    if (depth == 2) {
      // set aside children node, and insert new ones
      TreeNode *left = root->left;
      TreeNode *right = root->right;

      root->left = new TreeNode(val, left, nullptr);
      root->right = new TreeNode(val, nullptr, right);
      return root;
    }

    addOneRow(root->left, val, depth - 1);
    addOneRow(root->right, val, depth - 1);
    return root;
  }
};
