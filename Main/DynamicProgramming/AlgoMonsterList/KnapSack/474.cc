#include <string>
#include <vector>

using namespace std;

class Solution {
  public:
    int findMaxForm(vector<string> &strs, int m, int n) {
        vector<vector<vector<int>>> memo(strs.size(), vector<vector<int>>(m + 1, vector<int>(n + 1, -1)));
        return f(0, m, n, strs, memo);
    }

    int f(int i, int m, int n, vector<string> &strs, vector<vector<vector<int>>> &memo) {
        if (i >= strs.size()) return 0;
        if (m < 0 || n < 0) return 0;
        if (memo[i][m][n] != -1) return memo[i][m][n];

        // count 0's and 1's in current string
        int zs = 0;
        int os = 0;
        for (char &ch : strs[i]) {
            if (ch == '1') {
                os++;
            } else {
                zs++;
            }
        }

        // recursive relation
        int take = 0;
        if (m >= zs && n >= os) take = 1 + f(i + 1, m - zs, n - os, strs, memo);
        memo[i][m][n] = max(take, f(i + 1, m, n, strs, memo));
        return memo[i][m][n];
    }
};