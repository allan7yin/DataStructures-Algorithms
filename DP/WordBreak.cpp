#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        // O(mn) DP algorithm 
        int n = s.size();
        vector<bool> dp(n+1, false);
        dp[0] = true;
        for (int i = 0; i < n; i++) {
            for (string &entry : wordDict) {
                int k = entry.size();
                int num1 = max(0, i-k+1);
                if (i-k+1 >= 0 && s.substr(num1, k) == entry && dp[num1] == true) {
                    dp[i+1] = true;
                }
            }
        }
        return dp.back();
    }
};

int main() {
    vector<string> wordDict = {"cats","dog","sand","and","cat"};
    Solution sol;
    sol.wordBreak("catsandog", wordDict);

}