#include <string>
using namespace std;

int dp[100][100];
string word;
class Solution {
  public:
    int strangePrinter(string s) {
        int n = s.size();
        memset(dp, -1, sizeof(dp));
        word = s;
        return f(0, n - 1);
    }

    int f(int i, int j) {
        if (i > j) return 0;
        if (i == j) return 1;
        if (dp[i][j] != -1) return dp[i][j];

        dp[i][j] = INT_MAX;

        for (int k = i; k <= j; k++) {
            int val = f(i, k) + f(k + 1, j);
            dp[i][j] = min(dp[i][j], val);
        }

        if (word[i] == word[j]) {
            // only need to consider one of the ends
            // since we need only one to calculate the number of prints (printing aa is same as a -> same cost)
            dp[i][j] = min(dp[i][j], f(i, j - 1));
        } else {
            // now the same, so again, same as choosing one side, and add + 1, to account for the one not included in the interval anymore
            dp[i][j] = min(dp[i][j], f(i, j - 1) + 1);
        }
        return dp[i][j];
    }
};
