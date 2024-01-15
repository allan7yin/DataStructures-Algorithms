#include <vector>
using namespace std;

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        // same as unique paths 1, but now, if current square is occupied, set to 0
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<vector<int>> dp(m, vector<int>(n,0));
        int val = 1;
        for (int i = 0; i < m; i++) {
            dp[i][0] = (obstacleGrid[i][0] == 1) ? 0 : val;
            if (obstacleGrid[i][0] == 1) {
                val = 0;
            }
        }

        val = 1;
        for (int i = 0; i < n; i++) {
            dp[0][i] = (obstacleGrid[0][i] == 1) ? 0 : val;
            if (obstacleGrid[0][i] == 1) {
                val = 0;
            }
        }

        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                dp[i][j] = (obstacleGrid[i][j] == 0) ? (dp[i-1][j] + dp[i][j-1]) : 0;
            }
        }
        return dp[m-1][n-1];
    }
};

int main() {
    vector<int> row = {1,0};
    vector<vector<int>> m = {row};

    std::vector<std::vector<int>> matrix = {
        {0, 0, 0},
        {0, 1, 0},
        {0, 0, 0}
    };
    Solution sol;
    sol.uniquePathsWithObstacles(matrix);
}