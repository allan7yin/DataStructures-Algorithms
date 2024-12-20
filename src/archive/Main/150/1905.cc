#include <set>
#include <unordered_set>
#include <vector>
/*
The idea is to iterate through every square in grid 1, and change it once visited
- If every square in the dfs is also an island in grid2 -> we return true -> all return true, then we increment counter by 1
*/
using namespace std;

class Solution {
    vector<vector<bool>> visited;

  public:
    bool f(int r, int c, vector<vector<int>> &grid1, vector<vector<int>> &grid2) {
        if (r < 0 || r >= grid1.size() || c < 0 || c >= grid1[0].size() || grid2[r][c] != 1 || visited[r][c]) return true;

        // mark current as visited
        visited[r][c] = true;
        bool cond = grid1[r][c] == 1;

        cond = f(r + 1, c, grid1, grid2) && cond;
        cond = f(r - 1, c, grid1, grid2) && cond;
        cond = f(r, c + 1, grid1, grid2) && cond;
        cond = f(r, c - 1, grid1, grid2) && cond;

        return cond;
    }
    int countSubIslands(vector<vector<int>> &grid1, vector<vector<int>> &grid2) {
        int count = 0;
        visited = vector<vector<bool>>(grid1.size(), vector<bool>(grid1[0].size(), false));
        for (int i = 0; i < grid1.size(); i++) {
            for (int j = 0; j < grid1[0].size(); j++) {
                if (grid2[i][j] == 1 && !visited[i][j]) {
                    if (f(i, j, grid1, grid2)) count++;
                }
            }
        }
        return count;
    }
};