#include <vector>
using namespace std;

class Solution {
    vector<vector<int>> perms;

  public:
    vector<vector<int>> subsets(vector<int> &nums) {
        vector<int> s;
        f(nums, 0, s);
        return perms;
    }

    void f(vector<int> &nums, int i, vector<int> &s) {
        // either take or don't take
        if (i == nums.size()) {
            perms.push_back(s);
            return;
        }

        s.push_back(nums[i]);
        f(nums, i + 1, s);
        s.pop_back();
        f(nums, i + 1, s);
    }
};