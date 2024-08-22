#include <vector>
using namespace std;

// graph is one tree with extra edge, and remove it to obtain a tree

// ah I get it, have  n nodes, so n sets in union-find
// we keep adding edges until we have one component, the next edge will form an edge, done
class Solution {
    vector<int> parent;
    vector<int> rank;

  public:
    int find(int node) {
        // find the parent
        auto p = parent[node];
        while (p != parent[p]) {
            parent[p] = parent[parent[p]];
            p = parent[p];
        }
        return p;
    }
    bool unionf(int node1, int node2) {
        int par1 = find(node1), par2 = find(node2);
        if (par1 == par2) return true; // cycle detected

        // not same parent, union
        if (rank[par1] > rank[par2]) {
            rank[par1] += rank[par2];
            parent[par2] = par1;
        } else {
            rank[par2] += rank[par1];
            parent[par1] = par2;
        }

        return false;
    }
    vector<int> findRedundantConnection(vector<vector<int>> &edges) {
        int n = edges.size();
        vector<int> result;
        parent = vector<int>(n + 1, 0);
        for (int i = 1; i <= n; i++) {
            parent[i] = i;
        }

        // rank vector
        rank = vector<int>(n + 1, 1);

        for (auto &edge : edges) {
            // union the 2 end nodes
            if (unionf(edge[0], edge[1])) {
                result = edge;
                break;
            }
        }
        return result;
    }
};