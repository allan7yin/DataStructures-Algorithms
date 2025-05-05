#include "../bits/stdc++.h"
using namespace std;

/*
IMPORTANT: Just remember the idea:
- we first want to find min viable window, where we just increase right pointer
- once we find need = have -> use these, we try to shrink window

Time complexity: o(n + m)
*/
class Solution {
  public:
    string minWindow(string s, string t) {
        int m = s.size(), n = t.size();
        int start = 0;

        int window = INT_MAX;
        unordered_map<char, int> mpT;
        unordered_map<char, int> mpS;

        // intialize the map for T with its character counts
        for (int i = 0; i < n; i++) { // o(n)
            mpT[t[i]]++;
        }

        int have = 0, need = mpT.size();

        int l = 0;
        for (int r = 0; r < m; r++) { // iterate m times
            char curr = s[r];
            mpS[curr]++;
            if (mpS[curr] == mpT[curr]) {
                have++;
            }

            while (have == need) { // each character is only added once, and remove once -> amortized, this for loop is o(m)
                // see if we can shrink the window
                if (r - l + 1 < window) {
                    window = r - l + 1;
                    // need to save result
                    start = l;
                }

                mpS[s[l]]--;
                if (mpS[s[l]] < mpT[s[l]]) have--;
                l++;
            }
        }

        return (window == INT_MAX) ? "" : s.substr(start, window);
    }
};