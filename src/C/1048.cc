#include <string>
#include <vector>
using namespace std;

/*
- same as LIS (longest increasing subsequence)
- why does this runtime work?
- time complexity is O(n^2 * m) -> n^2 <= 256
- so, 256 * 10^3 is max -> very fast
*/
class Solution {
  public:
    bool isPredecessor(string &s1, string &s2) {
        if (s1.size() + 1 != s2.size()) return false;
        int i = 0, j = 0;
        while (i < s1.size() && j < s2.size()) {
            if (s1[i] == s2[j]) {
                i++;
            }
            j++;
        }
        return i == s1.size();
    }

    static bool compare(string &s1, string &s2) {
        return s1.size() < s2.size();
    }
    int longestStrChain(vector<string> &words) {
        sort(words.begin(), words.end(), compare);
        int n = words.size();
        int maxL = 1;
        vector<int> dp(n, 1);

        for (int i = 0; i < n; i++) {
            for (int j = i - 1; j >= 0; j--) {
                if (words[j].size() + 1 < words[i].size()) break;
                if (isPredecessor(words[j], words[i])) {
                    dp[i] = max(dp[i], 1 + dp[j]);
                    maxL = max(maxL, dp[i]);
                }
            }
        }
        return maxL;
    }
};