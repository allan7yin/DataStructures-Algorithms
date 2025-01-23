#include "bits/stdc++.h";

using namespace std;

class Solution {
  public:
    int lengthOfLongestSubstring(string s) {
        int maxLength = 0;
        unordered_set<char> w;

        for (int r = 0, l = 0; r < s.size(); r++) {
            while (w.count(s[r])) {
                w.erase(s[l]);
                l++;
            }

            w.insert(s[r]);
            maxLength = max(maxLength, r - l + 1);
        }
        return maxLength;
    }
};