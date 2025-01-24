#include "bits/stdc++.h";
using namespace std;

// runtime of this
// each state at position i is only computed once -> O(n) unique states, runtime is O(n)
class Solution {
    unordered_map<int, int> mem;

  public:
    int numDecodings(string s) {
        return f(s, 0);
    }

    int f(string &s, int i) {
        if (mem.find(i) != mem.end()) return mem[i];
        if (i == s.size()) return 1;
        if (s[i] == '0') return 0;
        int count = 0;
        if (i < s.size() - 1 && ((s[i] == '1' && s[i + 1] <= '9') || (s[i] == '2' && s[i + 1] <= '6'))) {
            // can eat 2
            count += f(s, i + 2);
        }

        // eat 1
        count += f(s, i + 1);
        return mem[i] = count;
    }
};