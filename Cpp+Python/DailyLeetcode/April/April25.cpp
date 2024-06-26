#include <algorithm>
#include <string>
#include <vector>

using namespace std;
/*
 * This is a DP question, we will maintain dp table, where table[i] represents
 * the longest ideal subsequence including s[i].
 *
 * the first solution is TLE -> brute-force. Now, look to reduce with
 * memoization
 */
class Solution {
public:
  int longestIdealString(string s, int k) {
    vector<int> dp(26, 0);
    for (int i = 0; i < s.size(); i++) {
      int sub_max = 0;
      char curr = s[i];
      int index = curr - 'a';
      int l = max(0, index - k);
      int r = min(25, index + k);

      for (int j = l; j <= r; j++) {
        sub_max = max(sub_max, dp[j]);
      }
      dp[index] = sub_max + 1;
    }

    // go through the dp table and return the max length
    int max_length = 0;
    for (int i = 0; i < dp.size(); i++) {
      max_length = max(max_length, dp[i]);
    }
    return max_length;
  }

  int longestIdealStringTLEVersion(string s, int k) {
    vector<string> dp(s.size(), "");
    dp[0] = s[0];
    for (int i = 1; i < s.size(); i++) {
      dp[i] += s[i];
      for (int j = 0; j < i; j++) {
        string temp = "";
        if (abs(dp[j].back() - s[i]) <= k) {
          // means we can add this onto dp[j]'s longest ideal string
          temp += dp[j];
          temp += s[i];
          if (temp.size() > dp[i].size()) {
            dp[i] = temp;
          }
        }
      }
    }
    // go through the dp table and return the max length
    int max_length = 0;
    for (int i = 0; i < dp.size(); i++) {
      max_length = max(max_length, (int)dp[i].size());
    }
    return max_length;
  }
};
