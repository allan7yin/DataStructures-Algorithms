#include <vector>
using namespace std;

// this might be easier to think of in recursive terms
class Solution {
public:
  int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid) {
    int m = obstacleGrid.size();
    int n = obstacleGrid[0].size();

    vector<vector<int>> dp(m, vector<int>(n, 0));
    // populate the base cases for this problem
    for (int i = 0; i < m; i++) {
      dp[i][0] = (obstacleGrid[i][0] == 1) ? 0 : (i == 0 ? 1 : dp[i - 1][0]);
    }

    for (int i = 0; i < n; i++) {
      dp[0][i] = (obstacleGrid[0][i] == 1) ? 0 : (i == 0 ? 1 : dp[0][i - 1]);
    }

    // now, recurese
    recurse(m - 1, n - 1, obstacleGrid, dp);
    return dp[m - 1][n - 1];
  }

  int recurse(int r, int c, vector<vector<int>> &obstacleGrid, vector<vector<int>> &dp) {
    if (r < 0 || c < 0 || obstacleGrid[r][c] == 1)
      return 0;
    if (dp[r][c] == 0) {
      dp[r][c] = recurse(r - 1, c, obstacleGrid, dp) + recurse(r, c - 1, obstacleGrid, dp);
    }
    return dp[r][c];
  }
};