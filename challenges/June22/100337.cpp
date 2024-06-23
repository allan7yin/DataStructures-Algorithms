#include <vector>
using namespace std;
// 100337. Maximize Total Cost of Alternating Subarrays
// this is not right

class Solution {
public:
  long long maximumTotalCost(vector<int> &nums) {
    int n = nums.size();
    vector<long long> dp(n + 1, INT_MIN);
    dp[0] = 0;

    vector<long long> prefixes = calculatePrefix(nums);

    for (int i = 0; i < n + 1; i++) {
      int maxVal = INT_MIN;
      for (int j = 0; j < i; j++) {
        maxVal = max(maxVal, dp[i] + (prefixes[j] - prefixes[i]));
      }
    }

    return dp[n];
  }

  vector<long long> calculatePrefix(vector<int> &nums) {
    vector<long long> prefixSums(nums.size() + 1);
    for (int i = 0; i < nums.size(); i++) {
      if (i % 2 == 0) {
        prefixSums[i + 1] = prefixSums[i] + nums[i];
      } else {
        prefixSums[i + 1] = prefixSums[i] - nums[i];
      }
    }
    return prefixSums;
  }
};
