#include <unordered_map>
#include <vector>

using namespace std;

// https://leetcode.com/problems/rank-transform-of-an-array/description/?envType=daily-question&envId=2024-10-02

class Solution {
  public:
    vector<int> arrayRankTransform(vector<int> &arr) {
        if (arr.size() == 0) return {};
        unordered_map<int, int> mp;
        vector<int> cpy = arr;
        vector<int> result;
        sort(cpy.begin(), cpy.end());

        int rank = 1;
        mp[cpy[0]] = 1;
        for (int i = 1; i < cpy.size(); i++) {
            if (cpy[i] != cpy[i - 1]) {
                rank++;
            }
            mp[cpy[i]] = rank;
        }

        for (int i = 0; i < arr.size(); i++) {
            result.push_back(mp[arr[i]]);
        }
        return result;
    }
};