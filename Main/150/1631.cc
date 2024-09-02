#include <map>
#include <queue>
#include <vector>
using namespace std;

class Solution {
  public:
    // run a modified dijkstras on this problem, remember this pattern of using pq and continuing if node is visited
    // shorter to write then searching for min cost in a vector

    // instead of keeping track of the distance to a node, we keep track of the max effort up to that node/square -> direct application of dijkstras
    int minimumEffortPath(vector<vector<int>> &heights) {
        int n = heights.size();
        int m = heights[0].size();
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<>> pq;
        vector<vector<int>> distance(n, vector<int>(m, INT_MAX));
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        vector<pair<int, int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

        pq.push({0, {0, 0}});

        while (!pq.empty()) {
            auto [currentEffort, position] = pq.top();
            int r = position.first, c = position.second;
            pq.pop();

            // if this square has been visited, return
            if (visited[r][c]) continue;
            visited[r][c] = true;

            // check if we have reached the sink node
            if (r == n - 1 && c == m - 1) return currentEffort;

            // move to the neighbour nodes
            for (auto &dir : directions) {
                int newR = r + dir.first;
                int newC = c + dir.second;

                if (newR >= 0 && newR < n && newC >= 0 && newC < m) {
                    int newEffort = max(currentEffort, abs(heights[newR][newC] - heights[r][c]));
                    if (newEffort < distance[newR][newC]) {
                        distance[newR][newC] = newEffort;
                        pq.push({newEffort, {newR, newC}});
                    }
                }
            }
        }
        return -1;
    }
};