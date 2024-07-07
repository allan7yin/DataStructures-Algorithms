#include <set>
#include <vector>
using namespace std;

// slow but this is to practice DFS, also since we are using set instead of
// unordered_set
class Solution {
  set<pair<int, int>> visited;

public:
  int islandPerimeter(vector<vector<int>> &grid) {
    for (int i = 0; i < grid.size(); i++) {
      for (int j = 0; j < grid[0].size(); j++) {
        if (grid[i][j] == 1) {
          return dfs(grid, i, j);
        }
      }
    }
    return 0;
  }

  int dfs(vector<vector<int>> &grid, int x, int y) {
    int result = 0;
    if (x < 0 || x >= grid.size() || y < 0 || y >= grid[0].size() ||
        grid[x][y] == 0) {
      // we got here from a land square, so + 1
      return 1;
    }
    pair<int, int> position = {x, y};
    if (visited.find(position) != visited.end()) {
      return 0;
    }

    visited.insert(position);
    result += dfs(grid, x + 1, y);
    result += dfs(grid, x, y + 1);
    result += dfs(grid, x - 1, y);
    result += dfs(grid, x, y - 1);
    return result;
  }
};
