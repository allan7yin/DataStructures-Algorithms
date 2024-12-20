#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
    unordered_map<int, vector<int>> mp;
    unordered_set<int> recStack;
    unordered_set<int> visited;
    bool cond = true;

  public:
    void f(int curr, int parent) {
        if (recStack.count(curr)) {
            cond = false;
            return;
        }
        if (visited.count(curr)) return;

        visited.insert(curr);
        recStack.insert(curr);
        for (auto &neighbour : mp[curr]) {
            if (neighbour != parent) f(neighbour, curr);
        }
        recStack.erase(curr);
    }
    bool validTree(int n, vector<vector<int>> &edges) {
        if (edges.size() == 0) {
            return n == 1;
        }
        // construct adjacency matrix, and retur false if cycle is detected -> does not need to be connected graph
        int components = 0;
        for (auto &edge : edges) {
            mp[edge[0]].push_back(edge[1]);
            mp[edge[1]].push_back(edge[0]);
        }

        if (mp.size() != n) return false;

        for (auto &kv : mp) {
            if (!visited.count(kv.first)) {
                components++;
            }
            f(kv.first, -1);
            recStack.clear();
        }
        return components == 1 ? cond : false;
    }
};