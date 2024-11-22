#include <string.h>
/*
The naive recursive method is easy to see, which I guess, memoizing the naive way
is correct ... lol
*/
int dp[31][1001];
const int M = 1e9 + 7;

class Solution {
  public:
    int numRollsToTarget(int n, int k, int target) {
        memset(dp, -1, sizeof(dp));
        return f(n, k, target, 0);
    }

    int f(int n, int k, int target, int sum) {
        if (sum == target && n == 0) return 1;
        if (n == 0 || sum > target) return 0;
        if (dp[n][sum] != -1) return dp[n][sum];

        dp[n][sum] = 0;

        for (int i = 1; i <= k; i++) {
            int val1 = f(n - 1, k, target, sum + i) % M;
            dp[n][sum] = (dp[n][sum] + val1) % M;
        }
        return dp[n][sum];
    }
};