#include <vector>
using namespace std;

class Solution {
    int n = 0;
    vector<vector<int>> result;

  public:
    vector<vector<int>> permute(vector<int> &nums) {
        n = nums.size();
        vector<int> s;
        vector<bool> visited(n, false);
        f(nums, 0, visited, s);
        return result;
    }

    void f(vector<int> &nums, int i, vector<bool> &v, vector<int> &s) {
        if (i == n) {
            result.push_back(s);
            return;
        }

        for (int j = 0; j < n; j++) {
            if (!v[j]) {
                v[j] = true;
                s.push_back(nums[j]);
                f(nums, i + 1, v, s);
                s.pop_back();
                v[j] = false;
            }
        }
    }
};