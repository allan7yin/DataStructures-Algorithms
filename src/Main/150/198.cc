#include <vector>
using namespace std;

class Solution {
  public:
    int rob(vector<int> &nums) {
        int n = nums.size();
        vector<int> dp(n + 1, 0);
        dp[0] = 0;
        dp[1] = nums[0];
        for (int i = 2; i <= n; i++) {
            for (int j = 0; j < i - 1; j++) {
                dp[i] = max(dp[i], nums[i - 1] + dp[j]);
            }
        }
        return max(dp[n], dp[n - 1]);
    }
};