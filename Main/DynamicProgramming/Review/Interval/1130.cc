#include <vector>
using namespace std;

class Solution {
  public:
    int mctFromLeafValues(vector<int> &arr) {
        int n = arr.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        vector<vector<int>> g(n, vector<int>(n, 0));

        // we can move these 2 for loops into one
        // we first populate the table g
        for (int i = n - 1; i >= 0; i--) {
            g[i][i] = arr[i];
            for (int j = i + 1; j < n; j++) {
                g[i][j] = max(arr[j], g[i][j - 1]);
            }
        }
        for (int i = n - 1; i >= 0; i--) {
            for (int j = i + 1; j < n; j++) {
                dp[i][j] = INT_MAX;
                for (int k = i; k < j; k++) {
                    dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j] + g[i][k] * g[k + 1][j]);
                }
            }
        }
        return dp[0][n - 1];
    }
};