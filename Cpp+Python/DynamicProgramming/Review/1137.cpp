// https://leetcode.com/problems/n-th-tribonacci-number/
#include <unordered_map>

class Solution {
public:
  int tribonacci(int n) {
    // do this recursively with memoization
    std::unordered_map<int, int> memo{
        {0, 0},
        {1, 1},
        {2, 1}};

    return dp(n, memo);
  }

  int dp(int n, std::unordered_map<int, int> &memo) {
    if (memo.find(n) == memo.end()) {
      memo[n] = dp(n - 1, memo) + dp(n - 2, memo) + dp(n - 3, memo);
    }
    return memo[n];
  }
};
