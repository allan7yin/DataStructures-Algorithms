#include <vector>
#include <map>
#include <string>

using namespace std;
/*
Link: https://leetcode.com/problems/group-anagrams/

How to solve:
    - we hash each word into a string -> alphabetical order, with a digit preceeding each letter indicating count 
*/
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> map;
        for (auto &str : strs) {
            string key = str;
            sort(key.begin(),key.end());
            map[key].emplace_back(str);
        }

        vector<vector<string>> solution;
        for (const auto &kv_pair : map) {
            solution.emplace_back(kv_pair.second);
        }

        return solution;
    }
};

int main() {}