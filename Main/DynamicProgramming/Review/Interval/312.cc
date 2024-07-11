#include <vector>
using namespace std;

int dp[302][302];

class Solution {
  public:
    int maxCoins(vector<int> &nums) {
        int n = nums.size();
        memset(dp, -1, sizeof(dp));
        nums.insert(nums.begin(), 1);
        nums.push_back(1);
        return f(nums, 1, n);
    }

    int f(vector<int> &nums, int i, int j) {
        if (i > j) return 0;
        if (dp[i][j] != -1) return dp[i][j];

        dp[i][j] = INT_MIN;
        for (int k = i; k <= j; k++) {
            int coins = nums[i - 1] * nums[k] * nums[j + 1];
            coins += f(nums, i, k - 1) + f(nums, k + 1, j);
            dp[i][j] = max(dp[i][j], coins);
        }
        return dp[i][j];
    }
};