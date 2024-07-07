#include <vector>

// this problem is very similar to coin change
class Solution {
public:
  int numSquares(int n) {
    std::vector<int> denom;
    int i = 1;
    while (i * i <= n) {
      denom.push_back(i * i);
      i++;
    }

    // now, perform coinchange
    std::vector<int> dp(n + 1, n + 1);
    dp[0] = 0;
    for (int i = 1; i < n + 1; i++) {
      for (int &val : denom) {
        if (i >= val) {
          dp[i] = std::min(dp[i], dp[i - val] + 1);
        }
      }
    }
    return dp[n];
  }
};