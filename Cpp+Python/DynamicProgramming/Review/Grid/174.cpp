#include <vector>
using namespace std;

// REVISIT THIS AGAIN -- NEED TO BE SUB 5MIN FOR THIS KIND OF PROBLEM
class Solution {
public:
  int calculateMinimumHP(vector<vector<int>> &dungeon) {
    int rows = dungeon.size();
    int cols = dungeon[0].size();
    vector<vector<int>> dp(rows, vector<int>(cols, INT_MAX));

    // Start from the bottom-right corner
    dp[rows - 1][cols - 1] = max(1, 1 - dungeon[rows - 1][cols - 1]);

    // fill in the last row
    for (int c = cols - 2; c >= 0; c--) {
      dp[rows - 1][c] = max(1, dp[rows - 1][c + 1] - dungeon[rows - 1][c]);
    }

    // fill in the last column
    for (int r = rows - 2; r >= 0; r--) {
      dp[r][cols - 1] = max(1, dp[r + 1][cols - 1] - dungeon[r][cols - 1]);
    }

    // fill in the rest
    for (int r = rows - 2; r >= 0; r--) {
      for (int c = cols - 2; c >= 0; c--) {
        dp[r][c] = max(1, min(dp[r + 1][c], dp[r][c + 1]) - dungeon[r][c]);
      }
    }

    return dp[0][0];
  }
};