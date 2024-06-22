#include <set>
#include <utility>
#include <vector>

// find the number of connected components, and keep track of excess connections
// if we have more excess connections than connected components, we have sol,
// else -1
class Solution {
public:
  int makeConnected(int n, std::vector<std::vector<int>> &connections) {
    std::set<int> visited;
  }

  std::pair<int, int> dfs(int source,
                          std::vector<std::vector<int>> &connections,
                          std::set<int> visited) {
    // add the current node to the visited
    visited.insert(source);

    return std::make_pair(1, 1);
  }
};
