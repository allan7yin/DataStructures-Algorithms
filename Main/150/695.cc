#include <vector>
using namespace std;

class Solution {
    int maxArea = 0;

  public:
    int f(vector<vector<int>> &grid, int r, int c) {
        if (r < 0 || c < 0 || r >= grid.size() || c >= grid[0].size()) return 0;
        if (grid[r][c] == 0) return 0;

        int size = 1;
        grid[r][c] = 0;
        // go all four directions
        size += f(grid, r + 1, c);
        size += f(grid, r - 1, c);
        size += f(grid, r, c + 1);
        size += f(grid, r, c - 1);
        return size;
    }

    int maxAreaOfIsland(vector<vector<int>> &grid) {
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == 1) {
                    maxArea = max(maxArea, f(grid, i, j));
                }
            }
        }
        return maxArea;
    }
};