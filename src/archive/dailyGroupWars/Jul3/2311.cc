#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

// something to remember
// want to solve this recursively
class Solution {
public:
  int longestSubsequence(string s, int k) {
    unordered_map<int, int> dp;
    return f(s, s.size() - 1, k, 0, 0, dp);
  }

  int f(string s, int i, long long k, int ln, long long sum, unordered_map<int, int> &dp) {
    if (i < 0)
      return 0;
    if (dp.count(i))
      return dp[i];

    int result = 0;
    int digit = s[i] - '0';
    int newSum = sum + digit * (1LL << ln);
    if (newSum <= k) {
      // take the number
      result = max(result, 1 + f(s, i - 1, k, ln + 1, newSum, dp));
    }

    // don't take
    result = max(result, f(s, i - 1, k, ln, sum, dp));
    return dp[i] = result;
  }
};