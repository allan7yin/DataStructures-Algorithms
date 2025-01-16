#include "bits/stdc++.h"

// idea, move from the capital towards the other cities, keeping track of the distance and seats remaining
// recuse from capital city -> maintain visited vector
class Solution {
  public:
    long long minimumFuelCost(vector<vector<int>> &roads, int seats) {
        int n = roads.size() + 1;
        vector<vector<int>> adj(n);
        vector<bool> visited(n, false);
        for (auto &road : roads) {
            adj[road[0]].push_back(road[1]);
            adj[road[1]].push_back(road[0]);
        }

        visited[0] = true;
        long long cost = 0;
        dfs(0, adj, visited, seats, cost);

        return cost;
    }

    int dfs(int curr, vector<vector<int>> &adj, vector<bool> &visited, int seats, long long &cost) {
        int passengers = 1;
        for (int next : adj[curr]) {
            if (!visited[next]) {
                visited[next] = true;
                passengers += dfs(next, adj, visited, seats, cost);
            }
        }

        if (curr != 0) {
            int cars = ceil((double)passengers / (double)seats);
            cost += cars;
        }

        return passengers;
    }
};

// o - o - o - o