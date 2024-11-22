#include <cstring>
#include <string>
#include <vector>
using namespace std;

class Solution {
  public:
    int numDistinct(string s, string t) {
        int n = s.size();
        int m = t.size();

        vector<vector<long long>> dp(n + 1, vector<long long>(m + 1, 0));

        // base case, when t = "", empty substring
        for (int i = 0; i <= n; i++) {
            dp[i][0] = 1;
        }

        // now loop through
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                // 2 cases to consider
                if (s[i - 1] == t[j - 1]) {
                    // 2 characters match, so, num equal is
                    dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
                } else {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }
        return dp[n][m];
    }
};