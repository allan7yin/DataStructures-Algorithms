#include <cstring>
#include <string>
using namespace std;

/*
 We have 2 strings that we are working with:
   a c e
 a
 b
 c
 d
 e

 if 2 characters are the same, then we move on to comparing the previous diagonal

*/
class Solution {
  public:
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size();
        int m = text2.size();
        int dp[n + 1][m + 1];

        memset(dp, 0, sizeof(dp));

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (text1[i - 1] == text2[j - 1]) {
                    // characters match
                    dp[i][j] = 1 + max(dp[i][j], dp[i - 1][j - 1]);
                } else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        return dp[n][m];
    }
};
