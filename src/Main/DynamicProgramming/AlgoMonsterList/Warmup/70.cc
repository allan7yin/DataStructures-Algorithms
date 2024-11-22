// problem: https://leetcode.com/problems/climbing-stairs/description/
class Solution {
public:
  int climbStairs(int n) {
    if (n < 3) {
      return n;
    }

    int result = 0, first = 1, second = 2, temp = 0;
    for (int i = 2; i < n; i++) {
      result = (first + second);
      temp = second;
      second = result;
      first = temp;
    }

    return result;
  }
  /*
  O(n) time and O(n) space -> can reduce this to 2 spaces
  int climbStairs(int n) {
      if (n == 1) {
          return 1;
      }
      vector<int> dp(n, 0);
      dp[0] = 1;
      dp[1] = 2;
      for (int i = 2; i < n; i++) {
          dp[i] = dp[i-1] + dp[i-2];
      }
      return dp[n-1];
  }
  */
};
