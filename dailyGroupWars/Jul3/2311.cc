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
    return recurse(s, 0, k, 0, 0, dp);
  }

  int recurse(string s, int i, int k, int ln, int sum, unordered_map<int, int> &dp) {
    if (i == s.size())
      return 0;
    if (dp.count(i))
      return dp[i];

    int result = 0;
    int digit = s[i] - '0';
    int newSum = sum + pow(2, ln);
    if (newSum <= k) {
      // take the number
      result = max(result, 1 + recurse(s, i + 1, k, ln + 1, newSum, dp));
    }

    // don't take
    result = max(result, recurse(s, i + 1, k, ln, sum, dp));
    return dp[i] = result;
  }
};