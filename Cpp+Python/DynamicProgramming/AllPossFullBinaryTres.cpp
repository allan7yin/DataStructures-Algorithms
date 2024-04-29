#include <vector>
#include <utility>
#include <unordered_map>
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
 * This is the brute-force solution, which optimize via memoization (caching)
 */
class Solution {
public:
  vector<TreeNode *> allPossibleFBT(int n) {
    unordered_map<int, vector<TreeNode *>> dp;
    return dfs(n, dp);
  }

  vector<TreeNode* > dfs(int n, unordered_map<int, vector<TreeNode *>> &dp) {
    if (n == 0) {
      return {};
    }
    if (n== 1) {
      TreeNode* curr = new TreeNode();
      return {curr};
    }
    if (dp.find(n) != dp.end()) {
      return dp[n];
    }

    vector<TreeNode *> results;
    // now, recurse, splitting the nodes to the left and the right 
    for (int l = 0; l < n; l++) {
      int r = n - l - 1;
      vector<TreeNode *> left_subtree = dfs(l, dp);
      vector<TreeNode *> right_subtree = dfs(r, dp);

      for (int i = 0; i < left_subtree.size(); i++) {
        for (int j = 0; j < right_subtree.size(); j++) {
          TreeNode *curr = new TreeNode(0, left_subtree[i], right_subtree[j]);
          results.push_back(curr);
        }
      }
    }
    dp[n] = results;
    return results;
  }
};
