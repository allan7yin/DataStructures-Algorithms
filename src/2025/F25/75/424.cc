#include "../bits/stdc++.h"
using namespace std;

class Solution {
  public:
    int characterReplacement(string s, int k) {
        int maxWindow = 0;
        int n = s.size();
        unordered_map<char, int> freq;

        int l = 0;
        for (int r = 0; r < n; r++) {
            freq[s[r]]++;

            int maxCount = 0;
            for (auto &kv : freq) {
                maxCount = max(maxCount, kv.second);
            }

            int window = r - l + 1;
            if (window - maxCount <= k) {
                maxWindow = max(maxWindow, window);
            } else {
                freq[s[l]]--;
                l++;
            }
        }

        return maxWindow;
    }
};