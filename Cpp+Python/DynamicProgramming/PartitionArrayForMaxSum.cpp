#include <vector>
using namespace std;

class Solution {
public:
  int maxSumAfterPartitioning(vector<int> &arr, int k) {
    int n = arr.size();
    vector<int> dp(n + 1, 0);

    for (int i = 1; i < n + 1; i++) {
      // we need this to start when looking at the past k values
      int temp_max_val = 0;
      for (int left = 1; left <= k && i - left >= 0; left++) {
        // find the max value in this range
        temp_max_val = max(temp_max_val, arr[i - left]);
        dp[i] = max(dp[i], dp[i - left] + left * temp_max_val);
      }
    }
    return dp[n];
  }
};
