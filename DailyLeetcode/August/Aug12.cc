#include <vector>
using namespace std;

class Solution {
    vector<vector<int>> result;

  public:
    vector<vector<int>> combinationSum2(vector<int> &candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<int> s;
        f(candidates, s, target, 0, 0);
        return result;
    }

    void f(vector<int> &candidates, vector<int> &s, int target, int i, int sum) {
        if (sum == target) {
            result.push_back(s);
            return;
        }

        if (sum > target || i >= candidates.size()) return;

        // take or don't take
        s.push_back(candidates[i]);
        f(candidates, s, target, i + 1, sum + candidates[i]);

        // don't take
        s.pop_back();
        while (i < candidates.size() - 1 && candidates[i] == candidates[i + 1]) {
            i++;
        }

        f(candidates, s, target, i + 1, sum);
    }
};