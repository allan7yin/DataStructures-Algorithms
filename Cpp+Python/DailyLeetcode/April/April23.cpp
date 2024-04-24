#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
public:
  vector<int> findMinHeightTrees(int n, vector<vector<int>> &edges) {
    if (n == 1) {
      return {0};
    }
    vector<int> result;
    vector<int> deg(n, 0); // degree
    vector<vector<int>> adj(n);
    for (auto &e : edges) {
      int v = e[0], w = e[1];
      adj[v].push_back(w);
      adj[w].push_back(v);
      deg[v]++;
      deg[w]++;
    }
    // now, we maintain a queue, and push the initial leaves into it
    queue<int> q;
    for (int i = 0; i < deg.size(); i++) {
      if (deg[i] == 1) {
        q.push(i);
      }
    }

    int remaining = n;
    while (!q.empty()) {
      int q_size = q.size();
      remaining -= q_size;
      for (int i = 0; i < q_size; i++) {
        // each one of these is degree of 1. We delete it, and then we check
        // if the other node the edge was connecting to also results that node
        // in having degree 1. If so, add it to the queue
        int top_node = q.front();
        q.pop();
        if (remaining == 0) {
          result.push_back(top_node);
        }
        for (int next : adj[top_node]) {
          if (--deg[next] == 1) {
            q.push(next);
          }
        }
      }
    }
    return result;
  }
};
