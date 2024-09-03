#include <vector>
using namespace std;

class Solution {
  public:
    int minCostClimbingStairs(vector<int> &cost) {
        int n = cost.size();
        vector<int> dp(n + 1);
        dp[1] = cost[0];
        dp[2] = cost[1];

        for (int i = 3; i <= n; i++) {
            dp[i] = cost[i - 1] + min(dp[i - 1], dp[i - 2]);
        }
        return min(dp[n], dp[n - 1]);
    }
};
