#include <vector>
using namespace std;

class Solution {
    vector<vector<int>> result;

  public:
    vector<vector<int>> combinationSum2(vector<int> &candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<int> sums;
        f(candidates, 0, target, sums, 0);
        return result;
    }

    void f(vector<int> &c, int i, int target, vector<int> &s, int sum) {
        if (sum == target) {
            result.push_back(s);
            return;
        } else if (sum > target || i == c.size()) {
            return;
        }

        s.push_back(c[i]);
        f(c, i + 1, target, s, sum + c[i]);
        s.pop_back();

        // imagine we had like 1 1 2 3 -> and target is 6
        // if we take first 1, we could end up with 1 -> 2 -> 3
        // if we take second 1, could also end up 1 -> 2 -> 3
        while (i < c.size() - 1 && c[i] == c[i + 1]) {
            i++;
        }
        f(c, i + 1, target, s, sum);
    }
};