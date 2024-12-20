#include <climits>
#include <vector>

using namespace std;

class Solution {
  public:
    vector<long long> minimumCosts(vector<int> &regular, vector<int> &express, int expressCost) {
        vector<long long> result;
        regular.insert(regular.begin(), 0);
        express.insert(express.begin(), 0);

        int n = regular.size();
        vector<vector<long long>> dp(2, vector<long long>(n, LLONG_MAX));

        // base cases
        dp[0][0] = 0;
        dp[1][0] = expressCost; // Starting on express route has an initial cost.

        for (int i = 1; i < n; i++) {
            // Min cost to reach station i via the regular route
            dp[0][i] = min(dp[0][i - 1] + regular[i], dp[1][i - 1] + regular[i]);
            // Min cost to reach station i via the express route
            dp[1][i] = min(dp[1][i - 1] + express[i], dp[0][i - 1] + expressCost + express[i]);
        }

        // Collect the minimum cost for reaching each station
        for (int i = 1; i < n; i++) {
            result.push_back(min(dp[0][i], dp[1][i]));
        }
        return result;
    }
};
