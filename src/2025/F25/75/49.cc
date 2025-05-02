#include "../bits/stdc++.h"
using namespace std;

/*
Solution:
- sort each string => n*mlog(m)
- 10^4 * (100 * log 100)
- log 100 ~ between 6 and 7, closer to 7
- so kind of constant factor
*/
class Solution {
  public:
    vector<vector<string>> groupAnagrams(vector<string> &strs) {
        vector<vector<string>> result;

        unordered_map<string, vector<string>> mp;
        for (string &str : strs) {
            string cpy = str;
            sort(cpy.begin(), cpy.end());
            mp[cpy].push_back(str);
        }

        for (auto [k, v] : mp) {
            result.push_back(v);
        }

        return result;
    }
};