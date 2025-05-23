#include "../bits/stdc++.h"
using namespace std;

class Solution {
  public:
    int maxProfit(vector<int> &prices) {
        int profit = 0;
        int n = prices.size();
        bool sell = false;

        for (int i = 0; i < n - 1; i++) {
            if (sell) {
                profit += prices[i];
                sell = false;
            }

            if (prices[i] < prices[i + 1]) {
                profit -= prices[i];
                sell = true;
            }
        }

        if (sell) {
            profit += prices.back();
        }

        return profit;
    }
};