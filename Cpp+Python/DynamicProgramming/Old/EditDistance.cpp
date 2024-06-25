#include <string>
#include <vector>
using namespace std;

/*
- Try using 2D DP Table
- SO, just like how we created 2D DP table for longest common subsequence, we follow a similar approach here
- we construct a 2D DP table, consider:
- reminder we are trying to change w1 into w2:
            w2
        | r o s
        h | 0 0 0 5
        o | 0 0 0 4
  w1    r | 0 0 0 3
        s | 0 0 0 2
        e | 0 0 0 1
        | 3 2 1 0

Again, we make the table +1 in dimensions than the lenth of the our words. These are base cases. Consider the right-most column.
This is saying, for w2, "", we need 5 actions to turn `horse` into `` (5 deletes). Now consider we are at i = e and j = o. So here,
we are asking, "what is the edit distance from `e` to `os`". So, obv, it is 2 (one swap and one add). At this step, we have 2 options:
    1. Add o to e, so that they match at `o`. This means we now move on on to next index in `os`, so s.
    2. Delete e, so then we have `` to `os`. This essentially maps to, we move onto the next index in `e`, which is ``, base case
    3. Swap `e` for `o`, in which case, we are now comparing `` to `s`, which is diagonal
We take whichever option results in MINIMUM number of operations.

We continue this from bottom right of table until top left, bottom-up, returning dp[0][0] then effectively gives us the min number of
operations to convert `horse` into `ros`, the solution to this question. DEFINTELY REDO THIS OFTEN AS IT IS KEY DP PROBLEM
*/
class Solution {
public:
  int minDistance(string word1, string word2) {
    int n = word1.size();
    int m = word2.size();

    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    // populate the base cses for the dp table
    for (int i = 0; i <= n; i++) {
      dp[i][m] = n - i;
    }
    for (int i = 0; i <= m; i++) {
      dp[n][i] = m - i;
    }

    // now, we iterate over the table
    for (int i = n - 1; i >= 0; i--) {
      for (int j = m - 1; j >= 0; j--) {
        if (word1[i] == word2[j]) {
          dp[i][j] = dp[i + 1][j + 1];
        } else {
          dp[i][j] = 1 + min(dp[i + 1][j], min(dp[i + 1][j + 1], dp[i][j + 1]));
        }
      }
    }
    return dp[0][0];
  }
};