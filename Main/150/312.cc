#include <cstring>
#include <vector>
using namespace std;

int dp[302][302];
// in many ways, this is DNC problem, if we pop the current balloon, then we can recurse on 2 halves ->
class Solution {
  public:
    int f(vector<int> &nums, int start, int end) {
        if (end < start) return 0;
        int maxVal = 0;

        if (dp[start][end] != -1) return dp[start][end];
        // pop the current balloon and recurse on the left and right
        for (int i = start; i <= end; i++) {
            // whats the issue with the below? When we do this, we're assuming the nums[i-1] balloon has not been popped yet, which is a problem
            // int val = nums[i - 1] * nums[i] * nums[i + 1];
            int val = nums[start - 1] * nums[i] * nums[end + 1];
            maxVal = max(maxVal, f(nums, start, i - 1) + f(nums, i + 1, end) + val);
        }
        dp[start][end] = maxVal;
        return maxVal;
    }

    int maxCoins(vector<int> &nums) {
        int n = nums.size();
        nums.insert(nums.begin(), 1);
        nums.push_back(1);
        memset(dp, -1, sizeof(dp));

        return f(nums, 1, n);
    }
};