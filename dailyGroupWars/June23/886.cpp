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
    unordered_set<int> visited;
    unordered_map<int, vector<int>> adj;

    for (auto &kv : dislikes) {
      adj[kv[0]].push_back(kv[1]);
      adj[kv[1]].push_back(kv[0]);
    }

    // now, we bfs
  }

  void bfs() {}
};