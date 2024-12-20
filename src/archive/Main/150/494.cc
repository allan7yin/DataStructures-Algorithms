#include <cstring>
#include <vector>
using namespace std;

int dp[21][1001];

class Solution {
  public:
    // let's do this top-down
    int findTargetSumWays(vector<int> &nums, int target) {
        memset(dp, -1, sizeof(dp));
        return f(nums, 0, target, 0);
    }

    int f(vector<int> &nums, int sum, int target, int i) {
        if (i == nums.size()) {
            if (sum == target) return 1;
            return 0;
        }
        if (dp[i][sum] != -1) return dp[i][sum];

        dp[i][sum] = f(nums, sum + nums[i], target, i + 1) + f(nums, sum - nums[i], target, i + 1);
        return dp[i][sum];
    }
};
