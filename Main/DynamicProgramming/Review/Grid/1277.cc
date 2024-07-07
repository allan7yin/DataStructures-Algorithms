#include <vector>
using namespace std;

class Solution {
public:
  int countSquares(vector<vector<int>> &matrix) {
    // we'll let dp[i][j] represent the largest square dimension that can be made with
    // i, j as the right bottom corner of the square
    int count = 0;
    int rows = matrix.size();
    int cols = matrix[0].size();
    vector<vector<int>> dp(rows, vector<int>(cols, 0));

    for (int r = 0; r < matrix.size(); r++) {
      for (int c = 0; c < matrix[0].size(); c++) {
        if (r == 0 || c == 0) {
          dp[r][c] = matrix[r][c];
          count += dp[r][c];
          continue;
        }

        // else, we check the min between
        int dim = 1 + min(dp[r - 1][c], min(dp[r - 1][c - 1], dp[r][c - 1]));
        dp[r][c] = (matrix[r][c] == 1) ? dim : 0;
        count += dp[r][c];
      }
    }
    return count;
  }
};