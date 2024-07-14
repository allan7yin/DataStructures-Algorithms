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
        if (i > j)
            return 0;
        if (dp[i][j] != -1)
            return dp[i][j];

        dp[i][j] = INT_MIN;
        for (int k = i; k <= j; k++) {
            /*
            why do we do this from i-1, k, and j+1?
            we are doing this step last -> in the interval of [i,j], since after bursting the balloon is removed from nums
            so, if k is the last one popped, then by the time we do pop it, every other balloon in [i, j] will have already been popped
            hence why we do nums[i - 1] * nums[k] * nums[j + 1]
            */
            int coins = nums[i - 1] * nums[k] * nums[j + 1];
            coins += f(nums, i, k - 1) + f(nums, k + 1, j);
            dp[i][j] = max(dp[i][j], coins);
        }
        return dp[i][j];
    }
};