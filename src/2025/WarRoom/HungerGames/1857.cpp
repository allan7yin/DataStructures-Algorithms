#include "../bits/stdc++.h"
using namespace std;

class Solution {
    unordered_map<int, vector<int>> adj;
    set<int> seen;
    string colors;
    bool found;
    vector<vector<int>> dp;
    int maxCount;

  public:
    int largestPathValue(string colors, vector<vector<int>> &edges) {
        this->colors = colors;
        int n = colors.size();
        found = false;
        maxCount = 0;
        dp.assign(n, vector<int>(26, 0));

        for (const auto &edge : edges) {
            adj[edge[0]].push_back(edge[1]);
        }

        vector<int> visited(n, 0);

        for (int i = 0; i < n; ++i) {
            if (visited[i] == 0) {
                dfs(i, visited);
                if (found) return -1;
            }
        }

        return found ? -1 : maxCount;
    }

  private:
    void dfs(int node, vector<int> &visited) {
        if (visited[node] == 1) {
            found = true;
            return;
        }
        if (visited[node] == 2) return;

        visited[node] = 1;
        seen.insert(node);

        vector<int> count(26, 0);
        count[colors[node] - 'a'] = 1;

        for (int next : adj[node]) {
            dfs(next, visited);
            if (found) return;
            for (int c = 0; c < 26; ++c) {
                count[c] = max(count[c], dp[next][c] + (c == colors[node] - 'a'));
            }
        }

        for (int c = 0; c < 26; ++c) {
            dp[node][c] = count[c];
            maxCount = max(maxCount, count[c]);
        }

        visited[node] = 2;
        seen.erase(node);
    }
};