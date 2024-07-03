#include <vector>
#include <unordered_map>
using namespace std;
/*
Link: https://leetcode.com/problems/cherry-pickup-ii/?envType=daily-question&envId=2024-02-10
- We'll solve this with DP 
*/
class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int ROWS = grid.size();
        int COLS = grid[0].size();
        vector<vector<int>> dp(COLS, vector<int>(COLS, 0));

        // base case 
        for (int c1 = 0; c1 < COLS; c1++) {
            for (int c2 = 0; c2 < COLS; c2++) {
                if (c1 == c2) {
                    dp[c1][c2] = 0;
                } else {
                    dp[c1][c2] = grid[0][c1] + grid[0][c2];
                }
            }
        }

        // build 
        vector<int> directions = {-1,0,1};
        for (int r = 1; r < ROWS; r++) {
            vector<vector<int>> temp(COLS, vector<int>(COLS, 0));
            for (int c1 = 0; c1 < COLS; c1++) {
                for (int c2 = 0; c2 < COLS; c2++) {
                    for (int &d1:directions) {
                        for (int &d2:directions) {
                            if (min(c1,c2) < 0 || max(c1,c2) == COLS || c1 == c2) {
                                continue;
                            }
                            temp[c1][c2] = max(
                                temp[c1][c2],
                                grid[r][c1] + grid[r][c2] + dp[c1+d1][c2+d2]
                            );
                        }
                    }
                }
            }
            dp = temp;
        }
        return dp[0][COLS-1];
        
    }
};

int main() {
    Solution sol;
    std::vector<std::vector<int>> grid = {
        {3, 1, 1},
        {2, 5, 1},
        {1, 5, 5},
        {2, 1, 1}
    };
    sol.cherryPickup(grid);
}
