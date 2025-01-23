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
            vector<string> grams;
            for (auto &word : kv.second) {
                grams.push_back(word);
            }
            result.push_back(grams);
        }
        return result;
    }
};