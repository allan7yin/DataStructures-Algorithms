#include <vector>
using namespace std;

/*
Classic take or don't take
*/

int dp[300][5000];

class Solution {
  public:
    int change(int amount, vector<int> &coins) {
        memset(dp, -1, sizeof(dp));
        int val = f(0, coins, amount, 0);
        return val;
    }

    int f(int i, vector<int> &coins, int amount, long long sum) {
        if (i >= coins.size()) return 0;
        if (sum > amount) return 0;
        if (sum == amount) return 1;

        if (dp[i][sum] != -1) return dp[i][sum];

        // coin i, take it or don't take
        // trick is, don't need 3rd case, where we take and move on
        // this would matter if we cared about number of coins needed to make amount, but since this one
        // is just counting, we don't want it as it will overcount
        int take2 = f(i, coins, amount, sum + coins[i]);
        int dont = f(i + 1, coins, amount, sum);

        dp[i][sum] = take2 + dont;
        return dp[i][sum];
    }
};