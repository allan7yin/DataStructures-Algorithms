#include <vector>
#include <utility>
using namespace std;

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        vector<pair<int,int>> dp(nums.size() + 1, make_pair(1,1));
        // first is max, second is min
        int result = nums[0]; 
        for (int i = 0; i < nums.size(); i++) {
            result = max(result, nums[i]);
            if (nums[i] == 0) {
                dp[i+1].first = 0;
                dp[i+1].second = 0;
                continue;
            }
            int prod1;
            int prod2;
            if (dp[i] == make_pair(0,0)) {
                prod1 = nums[i];
                prod2 = nums[i];
            } else {
                prod1 = nums[i] * dp[i].first;
                prod2 = nums[i] * dp[i].second;
            }

            dp[i+1].first = max(nums[i], max(prod1, prod2));
            dp[i+1].second = min(nums[i], min(prod1, prod2));
        }

        // return max first element in the array 
        for (int i = 1; i < dp.size(); i++) {
            result = max(result, dp[i].first);
        }
        return result;
    }
};

int main() {
    vector<int> nums = {-2,0,-1};
    Solution sol;
    sol.maxProduct(nums);
}