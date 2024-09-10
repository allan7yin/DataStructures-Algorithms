#include <cstring>
#include <vector>
using namespace std;

/*
The initial idea is to use DFS, but it will exceed the time constraints.
- The question is, how can memoize this question? -> 2d dp table
*/

int dp[201][201];

class Solution {
  public:
    int longestIncreasingPath(vector<vector<int>> &matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        memset(dp, -1, sizeof(dp));

        int maxLength = 1;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                // recurse in all 4 directions
                maxLength = max(maxLength, f(matrix, i, j, -1));
            }
        }
        return maxLength;
    }

    int f(vector<vector<int>> &matrix, int r, int c, int prev) {
        if (r < 0 || r >= matrix.size() || c < 0 || c >= matrix[0].size() || matrix[r][c] <= prev) return 0;

        if (dp[r][c] != -1) return dp[r][c];
        // recurse in all 4 directions
        int d1 = f(matrix, r + 1, c, matrix[r][c]);
        int d2 = f(matrix, r - 1, c, matrix[r][c]);
        int d3 = f(matrix, r, c + 1, matrix[r][c]);
        int d4 = f(matrix, r, c - 1, matrix[r][c]);

        int result = 1 + max(d1, max(d2, max(d3, d4)));
        dp[r][c] = result;
        return result;
    }
};