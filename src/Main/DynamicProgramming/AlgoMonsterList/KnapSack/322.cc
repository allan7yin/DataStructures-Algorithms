#include <vector>
using namespace std;

/*
Classic take or don't take
*/

int dp[12][(int)1e4];

class Solution {
  public:
    int coinChange(vector<int> &coins, int amount) {
        memset(dp, -1, sizeof(dp));
        int val = f(0, coins, amount, 0, 0);
        return (val == INT_MAX) ? -1 : val;
    }

    int f(int i, vector<int> &coins, int amount, long long sum, int c) {
        if (i >= coins.size()) return INT_MAX;
        if (sum > amount) return INT_MAX;
        if (sum == amount) return 0;

        if (dp[i][sum] != -1) return dp[i][sum];

        // coin i, take it and take again, or don't take
        long long take1 = f(i + 1, coins, amount, sum + coins[i], c + 1);
        long long take2 = f(i, coins, amount, sum + coins[i], c + 1);
        long long dont = f(i + 1, coins, amount, sum, c);

        if (take1 != INT_MAX) take1++;
        if (take2 != INT_MAX) take2++;

        dp[i][sum] = min(dont, min(take1, take2));
        return dp[i][sum];
    }
};