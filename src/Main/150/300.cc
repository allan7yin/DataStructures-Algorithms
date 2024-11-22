#include <vector>
using namespace std;

// review of the classic dp problem
class Solution {
  public:
    int lengthOfLIS(vector<int> &nums) {
        int n = nums.size();
        int maxLength = 0;

        vector<int> dp(n, 1);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (nums[j] < nums[i]) {
                    dp[i] = max(dp[i], 1 + dp[j]);
                }
            }
            maxLength = max(maxLength, dp[i]);
        }
        return maxLength;
    }
};