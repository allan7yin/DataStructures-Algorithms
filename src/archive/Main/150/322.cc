#include <map>
#include <vector>
using namespace std;

int dp[12][(int)1e4];
class Solution {
  public:
    // first do naive recursive solution, and then memoize
    int coinChange(vector<int> &coins, int amount) {
        memset(dp, -1, sizeof(dp));
        int result = f(coins, 0, amount, 0);
        return (result == INT_MAX) ? -1 : result;
    }

    int f(vector<int> &coins, int i, int amount, long sum) {
        // either take the current coin and stay, or move on
        if (amount == sum) {
            return 0;
        } else if (sum > amount || i >= coins.size()) {
            return INT_MAX;
        }

        if (dp[i][sum] != -1) return dp[i][sum];

        // take
        int t1 = f(coins, i, amount, sum + coins[i]);
        if (t1 != INT_MAX) t1++;
        // dont take
        int t2 = f(coins, i + 1, amount, sum);
        dp[i][sum] = min(t1, t2);
        return dp[i][sum];
    }
};