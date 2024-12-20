#include <vector>
using namespace std;

class Solution {
public:
  int minPathSum(vector<vector<int>> &grid) {
    int m = grid.size();
    int n = grid[0].size();
    for (int r = 0; r < m; r++) {
      for (int c = 0; c < n; c++) {
        int temp = INT_MAX;
        if (r > 0) {
          temp = grid[r - 1][c];
        }
        if (c > 0) {
          temp = min(temp, grid[r][c - 1]);
        }
        grid[r][c] += (temp < INT_MAX) ? temp : 0;
      }
    }
    return grid[m - 1][n - 1];
  }
};