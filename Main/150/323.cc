#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
    unordered_set<int> visited;
    unordered_map<int, vector<int>> mp;

  public:
    void f(int curr) {
        if (visited.count(curr)) return;

        visited.insert(curr);
        for (auto &neighbour : mp[curr]) {
            f(neighbour);
        }
    }
    int countComponents(int n, vector<vector<int>> &edges) {
        int components = 0;
        for (auto &edge : edges) {
            mp[edge[0]].push_back(edge[1]);
            mp[edge[1]].push_back(edge[0]);
        }

        if (mp.size() < n) components += (n - mp.size());

        for (auto &kv : mp) {
            if (visited.count(kv.first) == 0) components++;
            f(kv.first);
        }
        return components;
    }
};