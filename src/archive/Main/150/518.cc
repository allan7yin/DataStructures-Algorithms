#include <cstring>
#include <vector>
using namespace std;

int dp[301][5001];
class Solution {
  public:
    // typical top-down is easiest to think about
    int change(int amount, vector<int> &coins) {
        memset(dp, -1, sizeof(dp));
        return f(coins, amount, 0);
    }

    int f(vector<int> &coins, int amount, int i) {
        if (amount == 0) {
            return 1;
        }
        if (amount < 0 || i == coins.size()) return 0;

        if (dp[i][amount] != -1) return dp[i][amount];
        // 2 choices
        dp[i][amount] = f(coins, amount - coins[i], i) + f(coins, amount, i + 1);
        return dp[i][amount];
    }
};
