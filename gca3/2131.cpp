#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
  public:
    int longestPalindrome(vector<string> &words) {
        bool hasPal = false;
        int length = 0;
        unordered_map<string, int> mp;
        for (string &w : words) {
            mp[w]++;
        }

        for (auto &w : words) {
            if (mp.find(w) == mp.end()) continue;
            string rev = "";
            rev += w[1];
            rev += w[0];

            if (w == rev) {
                length += 4 * (mp[w] / 2);
                if (mp[w] % 2 == 1) hasPal = true;
            } else if (mp.find(rev) != mp.end()) {
                length += 4 * min(mp[w], mp[rev]);
            }
            mp.erase(rev);
            if (w != rev) mp.erase(w);
        }
        length += (hasPal) ? 2 : 0;
        return length;
    }
};