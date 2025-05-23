#include "../bits/stdc++.h"

using namespace std;

class Solution {
  public:
    bool checkInclusion(string s1, string s2) {
        if (s1.size() > s2.size()) return false;
        vector<int> c1(26, 0), c2(26, 0);

        for (auto ch : s1)
            c1[ch - 'a']++;
        for (int i = 0; i < s1.size(); i++)
            c2[s2[i] - 'a']++;

        int l = 0;

        if (c1 == c2) return true;
        for (int r = s1.size(); r < s2.size(); r++) {
            c2[s2[l] - 'a']--;
            c2[s2[r] - 'a']++;
            l++;
            if (c1 == c2) return true;
        }

        return false;
    }
};