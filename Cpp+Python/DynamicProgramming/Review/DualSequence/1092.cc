#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
  string shortestCommonSupersequence(string str1, string str2) {
    int n = str1.size();
    int m = str2.size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    // base case, i = 0 -> str1 is "", j = 0 -> str2 is ""

    for (int i = 0; i < n + 1; i++) {
      dp[i][0] = i;
    }

    for (int i = 0; i < m + 1; i++) {
      dp[0][i] = i;
    }

    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= m; j++) {
        if (str1[i - 1] == str2[j - 1]) {
          dp[i][j] = 1 + dp[i - 1][j - 1];
        } else {
          dp[i][j] = 1 + min(dp[i - 1][j], dp[i][j - 1]);
        }
      }
    }

    cout << dp[n][m];

    // now, obtain the string again
    string result;
    while (m > 0 && n > 0) {
      if (str1[n - 1] == str2[m - 1]) {
        result += str1[n - 1];
        n--;
        m--;
      } else if (dp[n - 1][m] < dp[n][m - 1]) {
        result += str1[n - 1];
        n--;
      } else {
        result += str2[m - 1];
        m--;
      }
    }

    while (m > 0) {
      result += str2[m - 1];
      m--;
    }

    while (n > 0) {
      result += str1[n - 1];
      n--;
    }
    reverse(result.begin(), result.end());
    return result;
  }
};