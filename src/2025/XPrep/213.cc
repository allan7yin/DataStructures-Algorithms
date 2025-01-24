#include "bits/stdc++.h";
using namespace std;

class Solution {
  public:
    int rob(vector<int> &nums) {
        int maxProfit = 0;
        int n = nums.size();
        if (n == 1) return nums[0];
        vector<int> dp(n + 1, 0);

        // from 0 to n-1
        dp[1] = nums[0];
        for (int i = 2; i <= n - 1; i++) {
            dp[i] = max(dp[i - 1], nums[i - 1] + dp[i - 2]);
        }

        maxProfit = max(maxProfit, dp[n - 1]);

        dp = vector<int>(n + 1, 0);
        dp[2] = nums[1];
        for (int i = 3; i <= n; i++) {
            dp[i] = max(dp[i - 1], nums[i - 1] + dp[i - 2]);
        }

        return max(maxProfit, dp[n]);
    }
};