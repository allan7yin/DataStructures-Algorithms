#include <vector>
using namespace std;

class Solution {
  public:
    vector<int> largestDivisibleSubset(vector<int> &nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<int> dp(n, 1);
        // normally, if we only care about the size of the subset, we can just look for max value in the dp table
        // and we would be fine

        // however, if we want the actual numbers in the set, we need to move through the table for this, we use prev
        // vector to keep track of all numbers in the same subset -> just move backwards through dp to find all
        vector<int> prev(n, -1);
        int maxi = 0;

        for (int i = 0; i < n; i++) {
            for (int j = i - 1; j >= 0; j--) {
                if (nums[i] % nums[j] == 0 || nums[j] % nums[i] == 0) {
                    if (1 + dp[j] > dp[i]) {
                        dp[i] = 1 + dp[j]; // want to construct maximum subset
                        prev[i] = j;
                    }
                }
            }
            if (dp[i] > dp[maxi]) {
                maxi = i;
            }
        }

        // now, reconstruct
        vector<int> result;
        while (maxi != -1) {
            result.push_back(nums[maxi]);
            maxi = prev[maxi];
        }
        return result;
    }
};