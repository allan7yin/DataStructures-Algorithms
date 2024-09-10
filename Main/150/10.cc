#include <string>
#include <vector>
using namespace std;

// memoize this
int dp[20][20];
class Solution {
  public:
    bool f(int i, int j, const string &s, const string &p) {
        // Base case: if we have consumed the entire pattern
        if (j == p.size()) {
            return i == s.size();
        }

        if (dp[i][j] != -1) return (dp[i][j] == 1) ? true : false;

        bool cond = false;
        bool first_match = (i < s.size() && (s[i] == p[j] || p[j] == '.'));

        // If there's a '*' in the pattern after the current character
        if (j + 1 < p.size() && p[j + 1] == '*') {
            // Either we skip the '*' (j+2) or use '*' to match multiple characters
            cond = (f(i, j + 2, s, p)) || (first_match && f(i + 1, j, s, p));
        } else {
            // Proceed with normal matching
            cond = first_match && f(i + 1, j + 1, s, p);
        }
        if (cond) {
            dp[i][j] = 1;
        } else {
            dp[i][j] = 0;
        }
        return cond;
    }

    bool isMatch(string s, string p) {
        memset(dp, -1, sizeof(dp));
        return f(0, 0, s, p);
    }
};
