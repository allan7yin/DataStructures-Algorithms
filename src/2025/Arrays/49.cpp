#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
  public:
    vector<vector<string>> groupAnagrams(vector<string> &strs) {
        unordered_map<string, vector<string>> mp;
        for (string &str : strs) {
            string key = str;
            sort(key.begin(), key.end());
            mp[key].push_back(str);
        }

        vector<vector<string>> result;
        for (auto &kv : mp) {
            result.push_back(kv.second);
        }

        return result;
    }
};

// run-time
// we need O(k log k) to insert each string into to the dictionary, and there are n
// so O(n*klogk) where second part is overshadowed