#include "bits/stdc++.h";
using namespace std;

class Solution {
    vector<vector<int>> mem;

  public:
    int coinChange(vector<int> &coins, int amount) {
        mem = vector<vector<int>>(coins.size(), vector<int>(amount + 1, -1));
        int result = f(coins, amount, 0);
        return (result == INT_MAX) ? -1 : result;
    }

    int f(vector<int> &coins, int remaining, int i) {
        if (remaining < 0 || i >= coins.size()) return INT_MAX;
        if (remaining == 0) {
            return 0;
        }

        if (mem[i][remaining] != -1) return mem[i][remaining];

        // take current coin and stay here
        int take = f(coins, remaining - coins[i], i);
        if (take != INT_MAX) take++;

        // take nothing and move on
        int skip = f(coins, remaining, i + 1);
        return mem[i][remaining] = min(take, skip);
    }
};