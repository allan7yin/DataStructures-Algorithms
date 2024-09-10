#include <string>
#include <vector>
using namespace std;

// for these types of questions -> we always have some sort of 2D dp method of solving

class Solution {
  public:
    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();

        vector<vector<int>> dp(n + 1, vector<int>(m + 1, INT_MAX));
        // basecases
        for (int i = 0; i <= n; i++) {
            dp[i][0] = i;
        }

        for (int j = 0; j <= m; j++) {
            dp[0][j] = j;
        }

        // think about main recursive logic
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (word1[i - 1] == word2[j - 1]) {
                    // then the edit distance at these 2 points is equal to the previous iteration
                    dp[i][j] = dp[i - 1][j - 1];
                } else {
                    // not the same means, we must either replace current one to match, or, delete, or insert
                    // option 1: replace
                    dp[i][j] = min(dp[i][j], 1 + dp[i - 1][j - 1]);

                    // option 2: insert
                    dp[i][j] = min(dp[i][j], 1 + dp[i][j - 1]);

                    // option 3 delete
                    dp[i][j] = min(dp[i][j], 1 + dp[i - 1][j]);
                }
            }
        }
        return dp[n][m];
    }
};