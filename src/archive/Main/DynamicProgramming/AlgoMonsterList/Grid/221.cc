#include <vector>
using namespace std;

class Solution {
public:
  int maximalSquare(vector<vector<char>> &matrix) {
    int rows = matrix.size();
    int cols = matrix[0].size();
    int maxEdge = 0;
    vector<vector<int>> dp(rows, vector<int>(cols, 0));

    for (int r = 0; r < matrix.size(); r++) {
      for (int c = 0; c < matrix[0].size(); c++) {
        if (r == 0 || c == 0) {
          dp[r][c] = (matrix[r][c] == '1') ? 1 : 0;
          maxEdge = max(maxEdge, dp[r][c]);
          continue;
        }

        int curr = 1 + min(dp[r - 1][c], min(dp[r - 1][c - 1], dp[r][c - 1]));
        if (matrix[r][c] == '1') {
          dp[r][c] = curr;
          maxEdge = max(maxEdge, curr);
        }
      }
    }
    return maxEdge * maxEdge;
  }
};