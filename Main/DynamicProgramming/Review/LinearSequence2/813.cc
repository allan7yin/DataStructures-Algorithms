#include <vector>
using namespace std;

/*
This is basically the same question as partition array for max sum-> follows same idea
only difference, is that I can see this being 2D DP table dp[i][j], where i is the index for
the prefix, and j is the value of number of partitions < k

do this top-down? try it

*/

double dp[100][100];

class Solution {
  public:
    double largestSumOfAverages(vector<int> &nums, int k) {
        // cannot use memset(dp, -1, sizeof(dp)) if dp is double
        // memset converts this to unsigned char -> -1 becomes -0XFF not a number
        // this is why ths outputs -nan (not a number)
        memset(dp, 0, sizeof(dp));
        return f(0, k, nums);
    }

    double f(int i, int k, vector<int> &nums) {
        if (i >= nums.size()) return 0;
        if (k <= 0) return INT_MIN; // we need to return this, as moment k == 0 && i < n, no longer valid sol. Making INT_MIN makes this invalid
        if (dp[i][k] != 0) return dp[i][k];
        double sum = 0;
        double avg = 0;
        int length = 0;
        dp[i][k] = INT_MIN;
        for (int j = i; j < nums.size(); j++) {
            // accumulate, from i to j, as the first partition, then recurse with k-1 remaining partitions
            sum += nums[j];
            length++;
            avg = sum / length;

            dp[i][k] = max(dp[i][k], avg + f(j + 1, k - 1, nums));
        }
        return dp[i][k];
    }
};