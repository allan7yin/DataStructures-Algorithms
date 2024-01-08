#include <vector>

using namespace std;

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int> dp(cost.size() + 1);
        dp[0] = 0;
        dp[1] = cost[0];

        for (int i = 2; i <= cost.size(); i++) {
            dp[i] = min(dp[i-2], dp[i-1]) + cost[i-1];
        }
        return min(dp[cost.size()], dp[cost.size()-1]);

    }
};

int main() {}