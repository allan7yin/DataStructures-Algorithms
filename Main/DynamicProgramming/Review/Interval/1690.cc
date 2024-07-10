#include <numeric>
#include <vector>
using namespace std;
// https://webcache.googleusercontent.com/search?q=cache:https://federico-feresini.medium.com/stone-game-vii-algorithms-visualizations-2fb68b4b5e6e&strip=0&vwsrc=1&referer=medium-parser
/*
=> recall that this is interval dp, so when we are doing interval dp, think of this as such
We want to have dp[i][j] represent the
*/
class Solution {
  vector<vector<int>> dp;

public:
  int stoneGameVII(vector<int> &stones) {
    int n = stones.size();
    dp = vector<vector<int>>(n, vector<int>(n, -1));
    int sum = accumulate(stones.begin(), stones.end(), 0);
    return f(0, stones.size() - 1, stones, sum);
  }

  int f(int i, int j, vector<int> &stones, int sum) {
    if (j <= i)
      return 0;

    // has been memoized before
    if (dp[i][j] != -1)
      return dp[i][j];

    // this is the key is that we are looking to maximize the different in scores
    // this is how each player plays optimally, so in this given step, we get score of
    // sum - stones[i] for one player, and then we want to subtract the max-score of the other player
    // which is the recursive step
    dp[i][j] = max(sum - stones[i] - f(i + 1, j, stones, sum - stones[i]),
                   sum - stones[j] - f(i, j - 1, stones, sum - stones[j]));
    return dp[i][j];
  }
};