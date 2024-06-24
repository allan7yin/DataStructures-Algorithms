#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
public:
  bool possibleBipartition(int n, vector<vector<int>> &dislikes) {
    // this is a graph colouring question
    // we just keep calling bfs
    unordered_map<int, vector<int>> adj;

    for (auto &kv : dislikes) {
      adj[kv[0]].push_back(kv[1]);
      adj[kv[1]].push_back(kv[0]);
    }
    vector<int> group(n + 1, 0);
    // now, we bfs
    for (int i = 1; i <= n; i++) {                // Changed loop to start from 1
      if (group[i] == 0 && !bfs(i, adj, group)) { // Check if node is unassigned before calling bfs
        return false;
      }
    }
    return true;
  }

  bool bfs(int node, unordered_map<int, vector<int>> &adj, vector<int> &group) {
    queue<int> q;
    q.push(node);
    group[node] = 1;

    while (!q.empty()) {
      int current = q.front();
      q.pop();
      for (int &neighbour : adj[current]) {
        if (group[neighbour] == 0) {
          // unassigned
          group[neighbour] = -group[current]; // Corrected to use current instead of node
          q.push(neighbour);
        } else if (group[neighbour] == group[current]) { // Fixed comparison operator
          return false;
        }
      }
    }
    return true;
  }
};