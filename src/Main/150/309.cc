#include <cstring>
#include <vector>
using namespace std;

// this question is important for remembering the concept of states in dp
class Solution {
  public:
    int maxProfit(vector<int> &prices) {
        int n = prices.size();
        int dp[n][3];
        // 3 sttes: not holding stock, holding stock, selling today and entering cooldown period
        memset(dp, 0, sizeof(dp));

        // base case
        dp[0][0] = 0;
        dp[0][1] = -prices[0];
        dp[0][2] = 0;

        for (int i = 1; i < n; i++) {
            // option 1 -> we don't have stock. So, th max is either from the previous day's cooldown or holding state
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][2]);

            // option 2 -> we have a stock, max profit earned is from prev days holding, or buying it today from no stock on prev day
            dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] - prices[i]);

            // option 3 -> have stock and selling today
            dp[i][2] = dp[i - 1][1] + prices[i];
        }
        return max(dp[n - 1][0], dp[n - 1][2]);
    }
};