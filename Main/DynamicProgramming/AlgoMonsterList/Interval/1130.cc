#include <vector>
using namespace std;

// let's try also doing this problem top-down
int dp[40][40];
int g[40][40];
class Solution {
  public:
    int mctFromLeafValues(vector<int> &arr) {
        int n = arr.size();
        memset(dp, -1, sizeof(dp));
        memset(g, 0, sizeof(g));
        // first, precompute g

        for (int i = n - 1; i >= 0; i--) {
            g[i][i] = arr[i];
            for (int j = i + 1; j < n; j++) {
                g[i][j] = max(g[i][j - 1], arr[j]);
            }
        }
        return f(0, n - 1);
    }

    int f(int i, int j) {
        if (i == j) return 0;
        if (dp[i][j] != -1) return dp[i][j];

        dp[i][j] = INT_MAX;
        for (int k = i; k < j; k++) {
            // every possible split, and recurse
            dp[i][j] = min(dp[i][j], f(i, k) + f(k + 1, j) + (g[i][k] * g[k + 1][j]));
        }
        return dp[i][j];
    }
};

// the below is bottom up, personally, I want to try using top-down more
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