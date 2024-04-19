#include <vector>
using namespace std;
/*
 * Classic DFS question, but this is a bit dumb -> better one is the rust
 * version
 */
class Solution {
public:
  int numIslands(vector<vector<char>> &grid) {
    int result = 0;
    for (int i = 0; i < grid.size(); i++) {
      for (int j = 0; j < grid[0].size(); j++) {
        if (dfs(grid, i, j) > 0) {
          result++;
        }
      }
    }
    return result;
  }

  int dfs(vector<vector<char>> &grid, int i, int j) {
    int count = 0;
    if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() ||
        grid[i][j] != '1') {
      return 0;
    }

    // Mark the current cell as visited
    grid[i][j] = '#';

    count++;
    count += dfs(grid, i - 1, j);
    count += dfs(grid, i + 1, j);
    count += dfs(grid, i, j - 1);
    count += dfs(grid, i, j + 1);
    return count;
  }
};
