#include <vector>
using namespace std;
/*
This is O(n^2) -> non-constant transition between dp states
*/
class Solution {
  public:
    int lengthOfLIS(vector<int> &nums) {
        int maxval = 1;
        int n = nums.size();
        vector<int> dp(n + 1, 1);

        for (int i = 1; i < n + 1; i++) {
            for (int j = 1; j < i; j++) {
                if (nums[i - 1] > nums[j - 1]) {
                    dp[i] = max(dp[i], 1 + dp[j]);
                    maxval = max(maxval, dp[i]);
                }
            }
        }
        return maxval;
    }
};