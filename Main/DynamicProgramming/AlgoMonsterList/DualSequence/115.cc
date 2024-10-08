#include <string>
#include <vector>

using namespace std;

class Solution {
public:
  int numDistinct(string s, string t) {
    int n = s.size();
    int m = t.size();
    vector<vector<long long>> dp(n + 1, vector<long long>(m + 1, 0));

    // base case -> t = empty string
    for (int i = 0; i <= n; ++i) {
      dp[i][0] = 1;
    }

    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= m; j++) {
        if (s[i - 1] == t[j - 1]) {
          // 2 options, match or choose not to
          if (dp[i][j] <= INT_MAX - dp[i - 1][j - 1] - dp[i - 1][j]) {
            dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
          }
        } else {
          if (dp[i][j] <= INT_MAX - dp[i - 1][j]) {
            dp[i][j] = dp[i - 1][j];
          }
        }
      }
    }
    return dp[n][m];
  }
};