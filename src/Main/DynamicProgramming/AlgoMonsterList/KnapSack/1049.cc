#include <vector>
using namespace std;
int dp[30][3001];
/*
Parition the stones into 2 groups -> minimize the difference in weight between the 2 groups
*/
class Solution {
  public:
    int lastStoneWeightII(vector<int> &stones) {
        memset(dp, -1, sizeof(dp));
        return f(0, 0, 0, stones);
    }

    int f(int i, int s1, int s2, vector<int> &nums) {
        if (i >= nums.size()) return abs(s1 - s2);
        int val = abs(s1 - s2);
        if (dp[i][val] != -1) return dp[i][val];

        int val1 = f(i + 1, s1 + nums[i], s2, nums);
        int val2 = f(i + 1, s1, s2 + nums[i], nums);

        dp[i][val] = min(val1, val2);
        return dp[i][val];
    }
};