#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

/*
 * Let's first try doing this via a brute force approach. In the brute force
 * method, we will start a traversal algorithm from every node, and keeping
 * track of depth. We can then sum all of thise depths to obtain a result.
 *
 * This will result in TLE. we'll look at the optimized method below.
 *
 *
 */
class Solution {
public:
  vector<int> sumOfDistancesInTree(int n, vector<vector<int>> &edges) {
    // this is TLE method, but it does at least work. Brute force solution
    // construct edge map
    vector<int> sums;
    unordered_map<int, vector<int>> edge_map;
    unordered_set<int> visited;
    for (auto &edge : edges) {
      edge_map[edge[0]].push_back(edge[1]);
      edge_map[edge[1]].push_back(edge[0]);
    }

    for (int i = 0; i < n; i++) {
      int temp = dfs(i, 0, edge_map, visited);
      sums.push_back(temp);
      visited.clear();
    }

    return sums;
  }

  int dfs(int root, int depth, unordered_map<int, vector<int>> &map,
          unordered_set<int> &visited) {
    if (visited.find(root) != visited.end()) {
      return 0;
    }

    visited.insert(root);

    int temp = 0;
    for (auto &node:map[root]) {
      temp += dfs(node, depth + 1, map, visited);
    }

    return temp + depth;
  }
};





