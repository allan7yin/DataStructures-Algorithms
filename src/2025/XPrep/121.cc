#include "bits/stdc++.h";

using namespace std;

class Solution {
  public:
    int maxProfit(vector<int> &prices) {
        int p = 0;
        for (int r = 0, l = 0; r < prices.size(); r++) {
            if (prices[r] < prices[l]) {
                l = r;
                continue;
            }

            p = max(p, prices[r] - prices[l]);
        }

        return p;
    }
};