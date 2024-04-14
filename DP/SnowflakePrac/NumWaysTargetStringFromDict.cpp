#include <vector>

using namespace std;

/*
 *
 * This is a very difficult problem. Remember, a common way of solving these
 * kinds of problems, is to first imagine the brute-force approach. Then, you
 * can often improve the runtime via caching, this is memoization!
 *
 */

class Solution {
public:
  int numWays(vector<string> &words, string target) {
    // first, let's pre-compute the frequency of each character at each position
    // in the strings in words (which are all of the same length)
    int n = words[0].size();
    vector<vector<int>> dp(n, vector<int>(26, 0));
    vector<vector<long>> cache(target.size(), vector<long> (words[0].size(), -1));

    // populate the dp matrix
    for (int i = 0; i < words[0].size(); i++) {
      for (int j = 0; j < words.size(); j++) {
        dp[i][words[j][i] - 'a']++;
      }
    }

    // now, we recurse on this, we create a cache, to cachet the number of ways
    // for a certain i,j pair.
    return recurse(dp, cache, 0, 0, target, words[0].size());
  }

  long long recurse(vector<vector<int>> &dp, vector<vector<long>> &cache,
              int i, int j, string target, int wordLimit) {
    // first check if we have obtained the target
 
    if (i == target.size()) {
      return 1;
    }
    if (j == wordLimit) {
      return 0;
    }
    if (cache[i][j] != -1) {
      return cache[i][j];
    }
    // now, we have 2 options, we either use the current character word[i][j]
    // , meaning we go to recurse(i+1, j+1). Or, we skip it, and move on, as
    // there may be the same characters ahead, that still allow us to build
    // target we combine these into our cache
    
    long count = 0;
    char curr = target[i] - 'a';
    count = recurse(dp, cache, i, j+ 1, target, wordLimit);
    count += (dp[j][curr] * recurse(dp, cache, i + 1, j + 1, target, wordLimit));
    return cache[i][j] = count % 1000000007;
  }
};
