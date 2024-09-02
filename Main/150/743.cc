#include <climits>
#include <set>
#include <unordered_map>
#include <utility>
#include <vector>
using namespace std;

class Solution {
  public:
    int findMin(const vector<int> &dist, const vector<bool> &visited) {
        int minIndex = -1;
        int minValue = INT_MAX;
        for (int i = 1; i < dist.size(); i++) {
            if (!visited[i] && dist[i] < minValue) {
                minValue = dist[i];
                minIndex = i;
            }
        }
        return minIndex;
    }

    int networkDelayTime(vector<vector<int>> &times, int n, int k) {
        vector<int> dist(n + 1, INT_MAX);
        vector<bool> visited(n + 1, false);
        dist[k] = 0;

        unordered_map<int, vector<pair<int, int>>> adj; // <from, <to, time>>
        for (auto &time : times) {
            adj[time[0]].emplace_back(time[1], time[2]);
        }

        for (int i = 0; i < n; i++) {
            int index = findMin(dist, visited);
            if (index == -1) break;

            visited[index] = true;

            for (auto &neighbour : adj[index]) {
                int to = neighbour.first;
                int time = neighbour.second;
                if (!visited[to] && dist[index] != INT_MAX && dist[index] + time < dist[to]) {
                    dist[to] = dist[index] + time;
                }
            }
        }

        int maxDist = 0;
        for (int i = 1; i <= n; i++) {
            if (dist[i] == INT_MAX) return -1;
            maxDist = max(maxDist, dist[i]);
        }

        return maxDist;
    }
};
