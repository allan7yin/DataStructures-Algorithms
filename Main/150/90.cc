#include <set>
#include <vector>
using namespace std;

class Solution {
    vector<vector<int>> result;
    set<vector<int>> mySet;
    int n = 0;

  public:
    vector<vector<int>> subsetsWithDup(vector<int> &nums) {
        sort(nums.begin(), nums.end());
        n = nums.size();
        vector<int> s;
        f(nums, 0, s);
        for (auto &k : mySet) {
            result.push_back(k);
        }
        return result;
    }

    void f(vector<int> &nums, int i, vector<int> &s) {
        if (i == n) {
            mySet.insert(s);
            return;
        }

        s.push_back(nums[i]);
        f(nums, i + 1, s);
        s.pop_back();
        f(nums, i + 1, s);
    }
};