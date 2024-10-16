#include <unordered_map>
#include <vector>

using namespace std;

/*
Runtime:
- sorting string is O(mlogm)
- do it for each string, n strings -> O(nmlogm)
*/
class Solution {
  public:
    vector<vector<string>> groupAnagrams(vector<string> &strs) {
        vector<vector<string>> res;
        unordered_map<string, vector<string>> mp;
        for (auto &str : strs) {
            string c = str;
            sort(c.begin(), c.end());
            mp[c].push_back(str);
        }

        for (auto &kv : mp) {
            res.push_back(kv.second);
        }

        return res;
    }
};