#include <climits>
#include <unordered_map>
#include <vector>
using namespace std;

/*
Initially, I thought this was a simple case of finding shortest path -> however, one part of the
question prevents such an easy solution.

The question asks us to return min cost path with at most k stops -> that is, at most k intermediate
nodes.

To then solve this, we use BellmanFord algorithm, where we continually update shortest path to a node
given the incoming arcs up to V times, we break early at k times. Then, we check whether the shortest
length path to the destination node is still infinity.
*/

class Solution {
  public:
    int findCheapestPrice(int n, vector<vector<int>> &flights, int src, int dst, int k) {
        // First construct the graph, let's do an adjacency list representation to save space
        unordered_map<int, vector<pair<int, int>>> adj; // from, <to, price>
        for (auto &flight : flights) {
            adj[flight[0]].push_back({flight[1], flight[2]});
        }

        vector<int> dist(n, INT_MAX);
        dist[src] = 0;

        for (int i = 0; i <= k; i++) {
            // Each iteration, make a copy of the vector
            vector<int> distCopy = dist;
            for (auto &kv : adj) {
                for (auto &w : kv.second) {
                    // Ensure the source distance is not INT_MAX before updating
                    if (dist[kv.first] != INT_MAX && distCopy[w.first] > dist[kv.first] + w.second) {
                        distCopy[w.first] = dist[kv.first] + w.second;
                    }
                }
            }
            dist = distCopy;
        }
        return (dist[dst] == INT_MAX) ? -1 : dist[dst];
    }
};
