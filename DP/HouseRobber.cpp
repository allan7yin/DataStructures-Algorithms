#include <vector>
using namespace std;

class Solution {
public:
    // optimized approach 
    int rob(vector<int>& nums) {
        if (nums.size() == 1) {
            return nums[0];
        }
        int prev2 = nums[0];
        int prev1 = max(nums[0], nums[1]);
        int current = prev1;

        for (int i = 2; i < nums.size(); i++) {
            current = max(prev1, prev2 + nums[i]);
            prev2 = prev1;
            prev1 = current;
        }
        return current;
    }
    // this is the first recursive approach, since we only need past 2 costs, don't need fill dp array, above is optimized approach -> use this first in interviews 
    int rob(vector<int>& nums) {
        if (nums.size() == 1) {
            return nums[0];
        }
        vector<int> dp(nums.size());
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);
        for (int i = 2; i < nums.size(); i++) {
            dp[i] = max(dp[i-1], nums[i] + dp[i-2]);
        }
        return dp[nums.size() - 1];
    }
};

int main() {}