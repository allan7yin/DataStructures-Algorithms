#include <vector>
using namespace std;

class Solution {
    vector<vector<int>> result;

  public:
    vector<vector<int>> combinationSum(vector<int> &candidates, int target) {
        vector<int> s;
        f(candidates, target, 0, s, 0);
        return result;
    }

    void f(vector<int> &c, int target, int i, vector<int> &s, int sum) {
        if (sum == target) {
            result.push_back(s);
            return;
        } else if (i == c.size() || sum > target) {
            return;
        }

        s.push_back(c[i]);
        f(c, target, i, s, sum + c[i]);
        s.pop_back();
        f(c, target, i + 1, s, sum);
    }
};