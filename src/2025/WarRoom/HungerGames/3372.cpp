#include "../bits/stdc++.h"
using namespace std;

/*
- do a BFS on every node in the first graph, maintaining a count of the number of nodes you can reach
  within at most k edges
- then, do the same for graph 2, but with k-1, and record this value
  - the max value (node with most connections to other nodes k-1 edges) -> record this value
- we'll connect this node from the second graph, with every node from first graph
- if we want max reachable nodes from node i, we will connect node i
*/
class Solution {
  public:
    vector<int> maxTargetNodes(vector<vector<int>> &edges1, vector<vector<int>> &edges2, int k) {
        vector<int> result;
        unordered_map<int, vector<int>> adj1;
        unordered_map<int, vector<int>> adj2;
        for (auto &e : edges1) {
            adj1[e[0]].push_back(e[1]);
            adj1[e[1]].push_back(e[0]);
        }

        for (auto &e : edges2) {
            adj2[e[0]].push_back(e[1]);
            adj2[e[1]].push_back(e[0]);
        }

        vector<int> dist1 = getDistances(adj1, k);
        vector<int> dist2 = getDistances(adj2, k - 1);
        int maxVal = *max_element(dist2.begin(), dist2.end());
        for (int &val : dist1) {
            val += maxVal;
        }

        return dist1;
    }

    vector<int> getDistances(unordered_map<int, vector<int>> &adj, int k) {
        queue<int> frontier;
        vector<int> result(adj.size());
        if (k < 0) return result;
        for (auto &[node, neighbours] : adj) {
            frontier.push(node);
            vector<int> distance(adj.size(), -1);
            int count = 1;
            distance[node] = 0;

            while (!frontier.empty()) {
                int size = frontier.size();
                // expand the frontier
                for (int i = 0; i < size; i++) {
                    int curr = frontier.front();
                    frontier.pop();

                    for (int next : adj[curr]) {
                        if (distance[next] == -1) {
                            distance[next] = distance[curr] + 1;
                            if (distance[next] <= k) {
                                frontier.push(next);
                                count++;
                            }
                        }
                    }
                }
            }
            result[node] = count;
        }
        return result;
    }
};