#include <vector>
using namespace std;

/*
 * This video was very helpful: https://www.youtube.com/watch?v=D8dODtHA1Zk
 * The key is to recognize we only need to find sum of distances for one root,
 * then for the rest, we can reroot the graph to adjust the sum of distances
 *
 * ->> this is known as re-rooting dp problems, should look more into this
 */ 

class Solution {
private:
  void dfs(int root, int parent, vector<vector<int>> &adj,
           vector<int> &distances, vector<int> &subtree_size) {
    subtree_size[root] = 1;
    for (auto &node:adj[root]) {
      if (node == parent) {
        continue;
      }
      distances[node] = 1 + distances[root];
      dfs(node, root, adj, distances, subtree_size);
      subtree_size[root] += subtree_size[node];
    }
  }

  void dfs2(int root, int parent, int sd, vector<vector<int>> &adj, vector<int> &subtree_size, vector<int> &result, int n) {
    result[root] = sd;

    for (auto &node:adj[root]) {
      if (node == parent) {
        continue;
      }
      int temp = sd - subtree_size[node] + (n - subtree_size[node]);
      dfs2(node, root, temp, adj, subtree_size, result, n);
    }

  }

public:
  vector<int> sumOfDistancesInTree(int n, vector<vector<int>> &edges) {
    vector<int> result(n, 0), distances(n, 0), subtree_size(n, 0);
    vector<vector<int>> adj(n);
    // let's first populate this
    for (auto &edge : edges) {
      adj[edge[0]].push_back(edge[1]);
      adj[edge[1]].push_back(edge[0]);
    }

    // call dfs to populate the distances and subtree_size vectors
    dfs(0, -1, adj, distances, subtree_size);
    int sd = 0;
    for (int &val:distances) {
      sd += val;
    }
    // now, we need to perform shifting logic 
    dfs2(0, -1, sd, adj, subtree_size, result, n);
    return result;
  }
};








