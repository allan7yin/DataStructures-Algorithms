#include "bits/stdc++.h"

using namespace std;

void dfs(int r, int c, vector<string> &grid) {
    if (r < 0 || r >= grid.size() || c < 0 || c >= grid[0].size() || grid[r][c] != '.')
        return;

    grid[r][c] = '#';

    dfs(r - 1, c, grid);
    dfs(r + 1, c, grid);
    dfs(r, c - 1, grid);
    dfs(r, c + 1, grid);
}

int main() {
    int n, m;
    cin >> n >> m;
    cin.ignore();

    vector<string> grid(n);

    for (int i = 0; i < n; i++) {
        getline(cin, grid[i]);
    }

    int count = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == '.') {
                dfs(i, j, grid);
                count++;
            }
        }
    }

    cout << count << endl;

    return 0;
}
