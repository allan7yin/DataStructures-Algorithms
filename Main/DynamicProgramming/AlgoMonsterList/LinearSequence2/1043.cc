#include <vector>

using namespace std;

class Solution {
  public:
    int maxSumAfterPartitioning(vector<int> &arr, int k) {
        // trick is, we need to look back at k previous indices in the dp table, so will have a
        // non-constant transition
        int n = arr.size();
        vector<int> dp(n + 1, 0);

        for (int i = 1; i < n + 1; i++) {
            int maxr = 0;
            for (int j = i; j > 0 && j > i - k; j--) {
                // last j are the one subarray, we multiply max of that subarray by the frequency of max val so far
                maxr = max(maxr, arr[j - 1]);
                dp[i] = max(dp[i], dp[j - 1] + maxr * (i - j + 1));
            }
        }
        return dp[n];
    }
};

// do this top-down
int dp[500][501];

class Solution {
  public:
    int maxSumAfterPartitioning(vector<int> &arr, int k) {
        memset(dp, -1, sizeof(dp));
        return f(0, arr, k);
    }

    int f(int i, vector<int> &arr, int k) {
        if (i >= arr.size()) return 0;
        if (dp[i][k] != -1) return dp[i][k];

        int maxl = 0;
        for (int j = 0; j < k && i + j < arr.size(); j++) {
            // sub-array of length at most k
            maxl = max(maxl, arr[i + j]);
            dp[i][k] = max(dp[i][k], (maxl * (j + 1)) + f(i + j + 1, arr, k));
        }
        return dp[i][k];
    }
};
