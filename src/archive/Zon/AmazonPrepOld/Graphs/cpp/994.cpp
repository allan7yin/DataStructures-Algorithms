#include <queue>
#include <utility>
#include <vector>

using namespace std;

class Solution {
  public:
    int orangesRotting(vector<vector<int>> &grid) {
        queue<pair<int, int>> q;
        int fresh = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == 2) q.push({i, j});
                if (grid[i][j] == 1) fresh++;
            }
        }

        int minutes = 0;
        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; i++) {
                auto node = q.front();
                int r = node.first;
                int c = node.second;

                // all 4 directions
                if (r + 1 < grid.size() && grid[r + 1][c] == 1) {
                    grid[r + 1][c] = 2;
                    q.push({r + 1, c});
                    fresh--;
                }

                if (r - 1 >= 0 && grid[r - 1][c] == 1) {
                    grid[r - 1][c] = 2;
                    q.push({r - 1, c});
                    fresh--;
                }

                if (c + 1 < grid[0].size() && grid[r][c + 1] == 1) {
                    grid[r][c + 1] = 2;
                    q.push({r, c + 1});
                    fresh--;
                }

                if (c - 1 >= 0 && grid[r][c - 1] == 1) {
                    grid[r][c - 1] = 2;
                    q.push({r, c - 1});
                    fresh--;
                }
                q.pop();
            }
            if (!q.empty()) minutes++;
        }

        return (fresh == 0) ? minutes : -1;
    }
};