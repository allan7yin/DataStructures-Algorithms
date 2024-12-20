#include <set>
#include <vector>

using namespace std;

class Solution {
    int n;
    int m;

  public:
    void f(set<pair<int, int>> &reached, vector<vector<int>> &heights, int r, int c, int h) {
        if (r < 0 || r >= n || c < 0 || c >= m || heights[r][c] < h || reached.count({r, c})) return;

        reached.insert({r, c});
        f(reached, heights, r + 1, c, heights[r][c]);
        f(reached, heights, r - 1, c, heights[r][c]);
        f(reached, heights, r, c + 1, heights[r][c]);
        f(reached, heights, r, c - 1, heights[r][c]);
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>> &heights) {
        // find all reachable squares starting from left and top
        n = heights.size();
        m = heights[0].size();

        set<pair<int, int>> lt;
        set<pair<int, int>> rb;

        for (int i = 0; i < n; i++) {
            f(lt, heights, i, 0, heights[i][0]);
            f(rb, heights, i, m - 1, heights[i][m - 1]);
        }

        for (int i = 0; i < m; i++) {
            f(lt, heights, 0, i, heights[0][i]);
            f(rb, heights, n - 1, i, heights[n - 1][i]);
        }

        vector<vector<int>> result;
        for (auto &k : lt) {
            if (rb.find(k) != rb.end()) {
                result.push_back({k.first, k.second});
            }
        }

        return result;
    }
};