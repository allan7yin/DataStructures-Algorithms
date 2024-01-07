// Jan 6th 2024:  https://leetcode.com/problems/arithmetic-slices-ii-subsequence/?envType=daily-question&envId=2024-01-07
#include <vector>
#include <unordered_map>
using namespace std;
/* 
    - Solve this question with DP 
    - For each index i, we say dp[i][diff] is the number of subsequences up to index i
      with difference `diff`
*/
/* 
    - Solve this question with DP 
    - For each index i, we say dp[i][diff] is the number of subsequences up to index i
      with difference `diff`
    - while we can use vector for diff, negative differences might be a problem, use hashmap instead 
*/
/* 
    - Solve this question with DP 
    - For each index i, we say dp[i][diff] is the number of subsequences up to index i
      with difference `diff`
    - while we can use vector for diff, negative differences might be a problem, use hashmap instead 
*/
class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        long long int result = 0;
        long long int diff = 0;
        
        vector<unordered_map<long long int, long long int>> dp(nums.size());
        
        for (int i = 1; i < nums.size(); i++) {
            for (int j = 0; j < i; j++) {
                diff = (long long)nums[i] - nums[j];
                dp[i][diff] += dp[j][diff] + 1;
                result += 1 + dp[j][diff];
            }
        }
        
        return result - ((nums.size() * (nums.size() - 1))/2);
    }
};

int main() {
    Solution sol;
    vector<int> nums = {0,2000000000,-294967296};
    sol.numberOfArithmeticSlices(nums);
}