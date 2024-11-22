#include <vector>
using namespace std;

/*
Classic knapsack -> take or don't take

after naive recursion -> memoize
*/

int dp[1000];

class Solution {
  public:
    int combinationSum4(vector<int> &nums, int target) {
        memset(dp, -1, sizeof(dp));
        return f(nums, target, 0);
    }

    int f(vector<int> &nums, int target, int s) {
        if (s == target) return 1;
        if (s > target) return 0;
        if (dp[s] != -1) return dp[s];

        // take or don't take
        dp[s] = 0;
        for (int &num : nums) {
            dp[s] += f(nums, target, s + num);
        }

        return dp[s];
    }
};