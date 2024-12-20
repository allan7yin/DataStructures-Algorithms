#include <vector>

using namespace std;

// idea: dfs from every gate
class Solution {
  public:
    void f(vector<vector<int>> &rooms, int r, int c, int d) {
        if (r < 0 || c < 0 ||
            r >= rooms.size() || c >= rooms[0].size() ||
            rooms[r][c] == 0 ||
            rooms[r][c] == -1)
            return;

        if (d < rooms[r][c]) {
            rooms[r][c] = d;
            f(rooms, r + 1, c, d + 1);
            f(rooms, r - 1, c, d + 1);
            f(rooms, r, c + 1, d + 1);
            f(rooms, r, c - 1, d + 1);
        }
    }
    void wallsAndGates(vector<vector<int>> &rooms) {
        for (int i = 0; i < rooms.size(); i++) {
            for (int j = 0; j < rooms[0].size(); j++) {
                if (rooms[i][j] == 0) {
                    f(rooms, i + 1, j, 1);
                    f(rooms, i - 1, j, 1);
                    f(rooms, i, j + 1, 1);
                    f(rooms, i, j - 1, 1);
                }
            }
        }
    }
};