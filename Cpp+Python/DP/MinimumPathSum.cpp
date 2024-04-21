#include <vector>
using namespace std;

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        // same way to solve as # of paths from top left to bottom right 
        int m = grid.size();
        int n = grid[0].size();
        int start_cost = grid[0][0];
        vector<vector<int>> dp(m, vector<int>(n,0));
        for (int i = 0; i < m; i++) {
            if (i != 0) {
                dp[i][0] += (grid[i][0] + dp[i-1][0]);
            } else {
                dp[i][0] += grid[i][0];
            }
        }

        for (int i = 0; i < n; i++) {
            if (i != 0) {
                dp[0][i] += (grid[0][i] + dp[0][i-1]);
            } else {
                dp[0][i] = grid[0][i];
            }
        }

        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                dp[i][j] += (grid[i][j] + min(dp[i-1][j], dp[i][j-1]));
            }
        }
        return dp[m-1][n-1];
    }
};

int main() {
    Solution sol;
        std::vector<std::vector<int>> matrix = {
        {1, 3, 1},
        {1, 5, 1},
        {4, 2, 1}
    };
    sol.minPathSum(matrix);
}