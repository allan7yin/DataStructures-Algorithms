#include <map>
#include <vector>
using namespace std;

/*
Fairly slow when we do this with top-down -> this ideally should be soled with bottom-up
*/
class Solution {
    // ALWAYS KEEP THIS IN CLASS -> being global fucks over LC's consecutive test cases
    map<pair<int, int>, int> memo;

  public:
    int findTargetSumWays(vector<int> &nums, int target) {
        return f(0, 0, nums, target);
    }

    int f(int i, int sum, vector<int> &nums, int target) {
        if (i >= nums.size()) {
            if (sum == target) {
                return 1;
            } else {
                return 0;
            }
        }
        auto p = make_pair(i, sum);
        if (memo.find(p) != memo.end()) return memo[p];

        // add or subtract
        memo[p] = f(i + 1, sum + nums[i], nums, target) + f(i + 1, sum - nums[i], nums, target);
        return memo[p];
    }
};