#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

// s = "ADOBECODEBANC", t = "ABC"
// s = "ADOBECODEBANC"
class Solution {
  public:
    string minWindow(string s, string t) {
        unordered_map<char, int> mp;
        unordered_map<char, int> window;

        for (char &ch : t) {
            mp[ch]++;
        }

        int start = 0;
        int wSize = INT_MAX;
        int have = 0, need = mp.size();
        int l = 0, r = 0;

        for (r; r < s.size(); r++) {
            char cur = s[r];
            window[cur]++;

            if (window[cur] == mp[cur]) {
                have++;
            }

            while (have == need) {
                if (r - l + 1 < wSize) {
                    wSize = r - l + 1;
                    start = l;
                }
                // check the current one
                window[s[l]]--;
                if (window[s[l]] < mp[s[l]]) {
                    // means moving left one will break our matching
                    have--;
                }
                l++;
            }
        }
        return (wSize == INT_MAX) ? "" : s.substr(start, wSize);
    }
};