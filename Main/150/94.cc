#include <deque>
#include <utility>
#include <vector>
using namespace std;

// bfs from every rotten orange
class Solution {
  public:
    int orangesRotting(vector<vector<int>> &grid) {
        // count number of fresh oranges in the beginning
        int fresh = 0;
        deque<pair<int, int>> dq;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[i].size(); j++) {
                if (grid[i][j] == 1) {
                    fresh++;
                } else if (grid[i][j] == 2) {
                    dq.push_back({i, j});
                }
            }
        }

        // run bfs
        int count = 0;
        while (!dq.empty() && fresh > 0) {
            int size = dq.size();
            for (int i = 0; i < size; i++) {
                // push adjacent squares onto this if they are fresh
                auto top = dq.front();
                int r = top.first, c = top.second;
                dq.pop_front();
                // Check all four directions
                if (r + 1 < grid.size() && grid[r + 1][c] == 1) {
                    grid[r + 1][c] = 2;
                    dq.push_back({r + 1, c});
                    fresh--;
                }
                if (r - 1 >= 0 && grid[r - 1][c] == 1) {
                    grid[r - 1][c] = 2;
                    dq.push_back({r - 1, c});
                    fresh--;
                }
                if (c + 1 < grid[0].size() && grid[r][c + 1] == 1) {
                    grid[r][c + 1] = 2;
                    dq.push_back({r, c + 1});
                    fresh--;
                }
                if (c - 1 >= 0 && grid[r][c - 1] == 1) {
                    grid[r][c - 1] = 2;
                    dq.push_back({r, c - 1});
                    fresh--;
                }
            }
            count++;
        }
        return (fresh == 0) ? count : -1;
    }
};