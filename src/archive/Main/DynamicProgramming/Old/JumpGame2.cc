#include <vector>
using namespace std;

class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, n+1);
        dp[0] = 0;
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (j + nums[j] >= i) {
                    dp[i] = min(dp[i], 1 + dp[j]);
                }
            }
        }
        return dp.back();

    }
};

int main() {
    vector<int> nums = {2,3,1,1,4};
    Solution sol;
    sol.jump(nums);
}