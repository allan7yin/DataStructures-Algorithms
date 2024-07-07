#include <string>
#include <vector>
using namespace std;

class Solution {
  vector<vector<int>> dp;
  string word;

public:
  string longestPalindrome(string s) {
    string result = "";
    int n = s.size();
    word = s;
    dp = vector<vector<int>>(n, vector<int>(n, -1));

    for (int i = 0; i < n; i++) {
      for (int j = 0; j <= i; j++) {
        if (isPalindrome(j, i)) {
          if (i - j + 1 > result.size()) {
            result = s.substr(j, i - j + 1);
          }
        }
      }
    }
    result = (s.size() == 1) ? s : result;
    return result;
  }

  int isPalindrome(int j, int i) {
    if (j > i) {
      return 1;
    }
    if (i == j) {
      dp[i][j] = 1;
      return 1;
    }
    if (dp[i][j] != -1) {
      // means memoized before
      return dp[i][j];
    }
    // otherwise, recuse and find
    if (word[i] == word[j]) {
      int value = isPalindrome(i + 1, j - 1);
      if (value) {
        dp[i][j] = 1;
      } else {
        dp[i][j] = 0;
      }
    } else {
      dp[i][j] = 0;
    }
    return dp[i][j];
  }
};