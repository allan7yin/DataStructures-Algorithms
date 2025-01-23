#include "bits/stdc++.h";
using namespace std;

// O(n) runtime
class Solution {
  public:
    bool isPalindrome(string s) {
        int l = 0, r = s.size() - 1;
        while (l <= r) {
            while (!isalnum(s[l]) && l < r) {
                l++;
            }

            while (!isalnum(s[r]) && l < r) {
                r--;
            }

            if (tolower(s[l]) != tolower(s[r])) return false;
            l++;
            r--;
        }
        return true;
    }
};