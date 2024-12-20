#include <string>
#include <vector>
using namespace std;

class Solution {
    vector<vector<int>> dp;
    string word;

  public:
    string longestPalindrome(string s) {
        string result = "";
        int n = s.size();
        word = s;
        dp = vector<vector<int>>(n, vector<int>(n, -1));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j <= i; j++) {
                if (isPalindrome(j, i)) {
                    if (i - j + 1 > result.size()) {
                        result = s.substr(j, i - j + 1);
                    }
                }
            }
        }
        result = (s.size() == 1) ? s : result;
        return result;
    }

    // not really tabulatiohn -> more of just caching reuslts from when we have chcked whether certain index ranges
    // are palindromes or not
    int isPalindrome(int j, int i) {
        if (j > i) {
            return 1;
        }
        if (i == j) {
            dp[j][i] = 1;
            return 1;
        }
        if (i == j + 1) {
            dp[j][i] = (word[j] == word[i]) ? 1 : 0;
            return dp[j][i];
        }
        if (dp[j][i] != -1) {
            return dp[j][i];
        }
        if (word[i] == word[j]) {
            dp[j][i] = isPalindrome(j + 1, i - 1);
        } else {
            dp[j][i] = 0;
        }
        return dp[j][i];
    }
};