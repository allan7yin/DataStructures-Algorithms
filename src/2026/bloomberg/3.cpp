#include <string>
#include <unordered_map>

using namespace std;

class Solution {
  public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> fmp;
        int max_length = 0;
        int n = s.size();

        int l = 0;
        for (int r = 0; r < n; r++) {
            fmp[s[r]]++;
            while (l < r && fmp[s[r]] > 1) {
                fmp[s[l]]--;
                if (fmp[s[l]] == 0) fmp.erase(s[l]);
                l++;
            }
            max_length = max(max_length, r - l + 1);
        }

        return max_length;
    }
};