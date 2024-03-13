#include <vector>
using namespace std;

/*
Jan 2nd, 2024
    - Convert to 2D array with conditions: https://leetcode.com/problems/convert-an-array-into-a-2d-array-with-conditions/description/?envType=daily-question&envId=2024-01-01
*/
class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        unordered_map<int, int> hmap;
        for (int &num: nums) {
            hmap[num]++;
        }
        vector<int> to_erase;
        vector<vector<int>> result;
        while (!hmap.empty()) {
            vector<int> row;
            for (auto &kv: hmap) {
                row.push_back(kv.first);
                kv.second--;
                if (kv.second == 0) {
                    to_erase.push_back(kv.first);
                }
            }
            result.push_back(row);

            for (int &i: to_erase) {
                hmap.erase(i);
            }
        }
        return result;
    }
};