#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
    unordered_map<string, bool> memo;

  public:
    bool wordBreak(string s, vector<string> &wordDict) {
        // just coin change
        if (s.empty()) return true;
        if (memo.find(s) != memo.end()) return memo[s];

        bool cond = false;
        for (string &word : wordDict) {
            int length = word.size();
            if (s.substr(0, length) == word) {
                string next = s.substr(length);
                if (wordBreak(next, wordDict)) {
                    memo[s] = true;
                    return memo[s];
                }
            }
        }
        memo[s] = false;
        return memo[s];
    }
};