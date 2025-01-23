#include "bits/stdc++.h"

using namespace std;

// create undirected graph view -> dfs from node 0 all the way until every node
// at every node, we will check if edge curr -> next, is in the directed graph. if it is not, reorder_count++;

// to check if an edge needs to be rerversed, say we have ab, we will need to maintain a unordered_map<int, unordered_set<int>> `next`
// each node can have > 1 neihbour -> we want to check if next is a neighbour in constant time -> so we use the set (amortized constant time)
// each next[i] indicates what comes next in the digraph, can compare like that

// time complexity -> O(n + m) --> n nodes, m arcs
class Solution {
    vector<vector<int>> adj;
    unordered_map<int, unordered_set<int>> next;
    vector<bool> visited;

  public:
    int minReorder(int n, vector<vector<int>> &connections) {
        visited = vector<bool>(n, false);
        adj.resize(n);
        for (auto &conn : connections) {
            adj[conn[0]].push_back(conn[1]);
            adj[conn[1]].push_back(conn[0]);
            next[conn[0]].insert(conn[1]);
        }

        return dfs(0);
    }

    int dfs(int curr) {
        int count = 0;
        visited[curr] = true;

        for (int neighbour : adj[curr]) {
            if (!visited[neighbour]) {
                // check if next is in, if it is, need to ++
                if (next[curr].count(neighbour)) {
                    count++;
                }
                count += dfs(neighbour);
            }
        }

        return count;
    }
};