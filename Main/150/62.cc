#include <cstring>
#include <vector>
using namespace std;

int dp[101][101];

class Solution {
  public:
    int uniquePaths(int m, int n) {
        int dp[m + 1][n + 1];
        // Initialize dp array to 0
        memset(dp, 0, sizeof(dp));
        for (int i = 1; i <= n; i++) {
            dp[1][i] = 1;
        }

        for (int i = 1; i <= m; i++) {
            dp[i][1] = 1;
        }

        // now iterate through the matrix
        for (int i = 2; i <= m; i++) {
            for (int j = 2; j <= n; j++) {
                dp[i][j] += (dp[i - 1][j] + dp[i][j - 1]);
            }
        }
        return dp[m][n];
    }
};