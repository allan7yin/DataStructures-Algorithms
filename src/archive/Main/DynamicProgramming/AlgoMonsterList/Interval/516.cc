#include <string>
#include <vector>
using namespace std;

class Solution {
  vector<vector<int>> dp;
  int m[1001][1001];

public:
  // recursive
  int longestPalindromeSubseq(string s) {
    int n = s.size();
    string s2 = s;
    m[n][n];
    memset(m, -1, sizeof(m));
    reverse(s2.begin(), s2.end());
    return f(s, s2, n, n);
  }

  int f(string s1, string s2, int i, int j) {
    if (i == 0 || j == 0)
      return 0;
    if (m[i][j] != -1)
      return m[i][j];
    if (s1[i - 1] == s2[j - 1]) {
      m[i][j] = 1 + f(s1, s2, i - 1, j - 1);
    } else {
      m[i][j] = max(f(s1, s2, i - 1, j), f(s1, s2, i, j - 1));
    }
    return m[i][j];
  }
  // this is the 2 dp tabulation, we should also be very comfortable doing dp recursively
  int longestPalindromeSubseqTAB(string s) {
    int n = s.size();
    dp = vector<vector<int>>(n + 1, vector<int>(n + 1, 0));
    string s2 = s;
    reverse(s.begin(), s.end());
    for (int i = 1; i < n + 1; i++) {
      for (int j = 1; j < n + 1; j++) {
        if (s[i - 1] == s2[j - 1]) {
          dp[i][j] = 1 + dp[i - 1][j - 1];
        } else {
          dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
      }
    }
    return dp[n][n];
  }
};