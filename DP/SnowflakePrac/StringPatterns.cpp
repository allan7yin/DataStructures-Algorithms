#include <vector>
using namespace std;
/*
 * This is from:
 * https://leetcode.com/discuss/interview-question/3761221/Snowflake-OA%3A-String-Patterns
 *
 * Link to solution can be found at:
 * https://www.geeksforgeeks.org/number-of-distinct-words-of-size-n-with-at-most-k-contiguous-vowels/
 *
 * The idea is, we create 2D DP map, where dp[i][j] is the number of numbers
 * where the length of the word is i and the last j characters are vowels
 *
 * j > i -> return 0, not possible
 * j == i: 5^i
 * j < i: in this case, we need to return dp[i][j]*5, since the next one is
 * vowel (5 poss) j == 0: in this case, sum (dp[i-1][0] to dp[i-1][k]) * 21,
 * where there are at most k vowels
 */
class Solution {
public:
  int numStringPatterns(int wordLen, int maxVowels) {
    vector<vector<long long int>> dp(wordLen + 1,
                                     vector<long long int>(maxVowels + 1, 0));

    // fill the dp array bottom up
    for (int i = 1; i < wordLen; i++) {
      for (int j = 1; j < maxVowels; j++) {
        if (j > i) {
          break;
        } else if (i == j) {
          dp[i][j] = pow(5, i);
        } else if (j == 0) {
          for (int k = 0; k < maxVowels; k++) {
            dp[i][j] += dp[i - 1][k];
          }
          dp[i][j] *= 21;
        } else {
          dp[i][j] = dp[i - 1][j - 1] * 5;
        }
      }
    }

    // find sum of all dp[i]
    long long int result = 0;
    for (int i = 0; i < dp.size(); i++) {
      result += dp[i][maxVowels];
    }
    return result;
  }
};
