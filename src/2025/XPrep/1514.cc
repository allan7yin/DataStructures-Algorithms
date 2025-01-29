#include "bits/stdc++.h";
using namespace std;

class Solution {
  public:
    double maxProbability(int n, vector<vector<int>> &edges, vector<double> &succProb, int start_node, int end_node) {
        unordered_map<int, vector<pair<int, double>>> adj;
        for (int i = 0; i < edges.size(); i++) {
            int a = edges[i][0];
            int b = edges[i][1];
            double prob = succProb[i];
            adj[a].emplace_back(b, prob);
            adj[b].emplace_back(a, prob);
        }

        vector<double> probabilities(n, 0.0);
        probabilities[start_node] = 1.0;

        priority_queue<pair<double, int>> pq;
        pq.push({1.0, start_node});

        while (!pq.empty()) {
            auto [current_prob, current_node] = pq.top();
            pq.pop();

            if (current_node == end_node) {
                return current_prob;
            }

            for (auto &[neighbor, prob] : adj[current_node]) {
                double new_prob = current_prob * prob;
                if (new_prob > probabilities[neighbor]) {
                    probabilities[neighbor] = new_prob;
                    pq.push({new_prob, neighbor});
                }
            }
        }

        return 0.0;
    }
};