#include <cstring>
#include <string>
#include <vector>
using namespace std;

int dp[101][101];

class Solution {
  public:
    bool isInterleave(string s1, string s2, string s3) {
        memset(dp, -1, sizeof(dp));
        return f(s1, s2, s3, 0, 0);
    }

    int f(string s1, string s2, string s3, int i, int j) {
        bool count = 0;
        if (i == s1.size() && j == s2.size()) return 1;

        if (dp[i][j] != -1) return dp[i][j];
        if (s1[i] == s3[i + j]) {
            count += f(s1, s2, s3, i + 1, j);
        }

        if (s2[j] == s3[i + j]) {
            count += f(s1, s2, s3, i, j + 1);
        }
        dp[i][j] = count;
        return count;
    }
};