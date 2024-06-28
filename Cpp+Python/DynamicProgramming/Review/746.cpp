#include <vector>

class Solution {
public:
  int minCostClimbingStairs(std::vector<int> &cost) {
    int n = cost.size();
    std::vector<int> dp(n + 1, 0);
    dp[0] = 0;
    dp[1] = cost[0];

    for (int i = 2; i < n + 1; i++) {
      dp[i] = std::min(dp[i - 1], dp[i - 2]) + cost[i - 1];
    }
    return std::min(dp[n], dp[n - 1]);
  }
};