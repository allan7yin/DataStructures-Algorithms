#include <climits>
#include <cstring>
#include <iostream>
#include <vector>

using namespace std;

int dp[100][(int)1e6];

class Solution {
  public:
    int coinChange(vector<int> &coins, int target) {
        memset(dp, -1, sizeof(dp));
        int val = f(0, coins, target, 0);
        return (val == INT_MAX) ? -1 : val;
    }

    int f(int i, vector<int> &coins, int target, long long sum) {
        if (sum > target) return INT_MAX;
        if (sum == target) return 0;
        if (i >= (int)coins.size()) return INT_MAX;

        if (dp[i][sum] != -1) return dp[i][sum];

        // Take the coin and stay on the same index, or move to the next index
        long long take = f(i, coins, target, sum + coins[i]);
        long long dont = f(i + 1, coins, target, sum);

        if (take != INT_MAX) take++;

        dp[i][sum] = min(dont, take);
        return dp[i][sum];
    }
};

int main() {
    int numCoins, target;
    cin >> numCoins >> target;

    vector<int> coins(numCoins);
    for (int i = 0; i < numCoins; i++) {
        cin >> coins[i];
    }

    Solution sol = Solution();
    cout << sol.coinChange(coins, target) << endl;
}