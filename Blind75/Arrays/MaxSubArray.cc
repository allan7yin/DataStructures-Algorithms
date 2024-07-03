#include <vector>
using namespace std;

class Solution {
public:
  int maxSubArray(vector<int> &nums) {
    int n = nums.size();
    vector<int> dp(n, 0);
    dp[0] = nums[0];
    int maxSum = dp[0];

    for (int i = 1; i < n; i++) {
      dp[i] = nums[i] + max(0, dp[i - 1]);
      maxSum = max(maxSum, dp[i]);
    }
    return maxSum;
  }
};
