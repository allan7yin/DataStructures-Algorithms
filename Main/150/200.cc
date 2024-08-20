#include <vector>
using namespace std;

// easy question -> dfs on every square that is one
class Solution {
  public:
    void f(vector<vector<char>> &grid, int r, int c) {
        if (r < 0 || c < 0 || r >= grid.size() || c >= grid[0].size()) return;
        if (grid[r][c] == '0') return;

        grid[r][c] = '0';
        // go all four directions
        f(grid, r + 1, c);
        f(grid, r - 1, c);
        f(grid, r, c + 1);
        f(grid, r, c - 1);
    }

    int numIslands(vector<vector<char>> &grid) {
        int count = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == '1') {
                    count++;
                    f(grid, i, j);
                }
            }
        }
        return count;
    }
};