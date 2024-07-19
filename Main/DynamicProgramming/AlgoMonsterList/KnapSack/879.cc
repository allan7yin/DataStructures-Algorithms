#include <vector>
using namespace std;

/*
Knapsack - can commit, or not commit, each crime
*/

int dp[105][105][105];

class Solution {
    vector<int> group;
    vector<int> profit;
    int minProfit;
    int n;
    int M = 1e9 + 7;

  public:
    int profitableSchemes(int n, int minProfit, vector<int> &group, vector<int> &profit) {
        memset(dp, -1, sizeof(dp));
        this->group = group;
        this->profit = profit;
        this->minProfit = minProfit;
        this->n = n;
        return f(0, 0, 0);
    }

    // i is crime, at each crime, we determine if we want to allocate members and earn profit from it or not
    int f(int i, int r, int p) {
        if (r > n) return 0;
        if (i >= profit.size()) return (p >= minProfit) ? 1 : 0;
        if (dp[i][r][p] != -1) return dp[i][r][p];

        // Clamp profit index to minProfit to avoid out of bounds
        int newProfit = min(p + profit[i], minProfit);

        // we either take this crime, or don't take it
        int v1 = f(i + 1, r + group[i], newProfit) % M;
        int v2 = f(i + 1, r, p) % M;
        dp[i][r][p] = (v1 + v2) % M;
        return dp[i][r][p];
    }
};