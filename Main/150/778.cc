#include <queue>
#include <vector>
using namespace std;

class Solution {
  public:
    int swimInWater(vector<vector<int>> &grid) {
        int n = grid.size();
        int m = grid[0].size();

        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<>> pq;
        vector<vector<int>> dist(n, vector<int>(m, INT_MAX));
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        vector<pair<int, int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

        dist[0][0] = grid[0][0];
        pq.push({grid[0][0], {0, 0}});

        while (!pq.empty()) {
            auto [currH, position] = pq.top();
            pq.pop();
            int r = position.first, c = position.second;

            if (visited[r][c]) continue;
            visited[r][c] = true;

            if (r == n - 1 && c == m - 1) return currH; // reached the bottom right square

            for (auto &dir : directions) {
                int newR = r + dir.first;
                int newC = c + dir.second;

                if (newR >= 0 && newR < n && newC >= 0 && newC < m) {
                    int newH = max(currH, grid[newR][newC]);
                    if (newH < dist[newR][newC]) {
                        dist[newR][newC] = newH;
                        pq.push({newH, {newR, newC}});
                    }
                }
            }
        }
        return 1;
    }
};