#include <numeric>
#include <vector>
using namespace std;

vector<vector<int>> dp;
int hs;

class Solution {
  public:
    // we need to solve this with 2D-DP: dp[i][j] stores whether its possible to have sum
    // j with the first i index values => I think its easier to think of this in bottom-up
    bool canPartitionBU(vector<int> &nums) {
        int n = nums.size();
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum % 2 == 1) return false;

        vector<vector<bool>> dp(n + 1, vector<bool>((sum / 2) + 1));
        dp[0][0] = 1;
        for (int i = 1; i < n + 1; i++) {
            // check all possible subsums
            for (int j = 0; j <= sum / 2 + 1; j++) {
                if (dp[i - 1][j]) dp[i][j] = true;

                // either take this number or we don't
                if (j >= nums[i - 1]) {
                    // first is not taking it, second is taking it
                    dp[i][j] = dp[i][j] || dp[i - 1][j - nums[i - 1]];
                }
            }
        }
        return dp[n][sum / 2];
    }

    // let's try the above top-down as well, memoize it
    bool canPartition(vector<int> &nums) {
        int n = nums.size();
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum % 2 == 1) return false;
        hs = sum / 2;
        dp = vector<vector<int>>(n, vector<int>(hs + 1, -1));

        return f(0, nums, 0);
    }

    bool f(int i, vector<int> &nums, int sum) {
        if (i >= nums.size() || (sum > hs)) return false;
        if (sum == hs) return true;
        if (dp[i][sum] != -1) return dp[i][sum];

        dp[i][sum] = f(i + 1, nums, sum + nums[i]) || f(i + 1, nums, sum);
        return dp[i][sum];
    }

    // naive recursive solution
    bool canPartitionNaive(vector<int> &nums) {
        return fNaive(0, nums, 0, 0);
    }

    bool fNaive(int i, vector<int> &nums, int s1, int s2) {
        if (i == nums.size()) return (s1 == s2);
        // have not reched end
        bool res = fNaive(i + 1, nums, s1 + nums[i], s2) || fNaive(i + 1, nums, s1, s2 + nums[i]);
    }
};