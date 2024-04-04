#include <string>
#include <vector>
using namespace std;

/*
This is a very important question: https://leetcode.com/problems/longest-common-subsequence/description/
- The fundamential idea is a 2D table. Every pair of a substring, we are looking to find the longest common subsequence between those
- this problem lays a foundation for many other problems, and is core problem in DP
*/
// make 2D DP table

class Solution {
public:
  int longestCommonSubsequence(string text1, string text2) {
    int n = text1.size();
    int m = text2.size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    for (int i = n - 1; i >= 0; i--) {
      for (int j = m - 1; j >= 0; j--) {
        if (text1[i] == text2[j]) {
          dp[i][j] = 1 + dp[i + 1][j + 1];
        } else {
          dp[i][j] = max(dp[i][j + 1], dp[i + 1][j]);
        }
      }
    }
    return dp[0][0];
  }
};