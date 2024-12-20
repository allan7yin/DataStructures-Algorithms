#include <string>
#include <unordered_map>

using namespace std;

class Solution {
    unordered_map<int, int> mp;

  public:
    // lets do this top-down method
    int numDecodings(string s) {
        return f(s, 0);
    }

    int f(string s, int i) {
        // 2 options -> take the current character and the next, or, just take current and move on
        int count = 0;
        if (mp.find(i) != mp.end()) return mp[i];
        if (i == s.size()) return 1;
        if (i > s.size() || s[i] == '0') return 0;

        // single digit
        count += f(s, i + 1);

        // double didgit
        if (i < s.size() - 1 && ((s[i] == '1' && s[i + 1] <= '9') || (s[i] == '2' && s[i + 1] <= '6'))) {
            count += f(s, i + 2);
        }
        mp[i] = count;
        return count;
    }
};