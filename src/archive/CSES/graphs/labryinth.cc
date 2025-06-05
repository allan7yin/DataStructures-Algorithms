#include "bits/stdc++.h"

using namespace std;

// bfs shortest path problem
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;
    vector<string> rows(n);

    cin.ignore();

    for (int i = 0; i < n; i++) {
        getline(cin, rows[i]);
    }

    // find start and end location
    int s_r = 0, s_c = 0, e_r = 0, e_c = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (rows[i][j] == 'A') {
                s_r = i;
                s_c = j;
            }

            if (rows[i][j] == 'B') {
                e_r = i;
                e_c = j;
            }
        }
    }

    queue<tuple<int, int, string>> q;
    q.push(make_tuple(s_r, s_c, ""));

    vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}}; // up, down, left, right
    vector<char> dir_chars = {'U', 'D', 'L', 'R'};

    rows[s_r][s_c] = '#';

    bool found = false;
    while (!q.empty()) {
        auto top = q.front();
        q.pop();
        if (get<0>(top) == e_r && get<1>(top) == e_c) { // by bfs --> first one is shortest path for sure
            found = true;
            cout << "YES" << '\n';
            cout << get<2>(top).size() << '\n';
            cout << get<2>(top) << '\n';
            break;
        }

        for (int i = 0; i < directions.size(); i++) {
            int new_r = get<0>(top) + directions[i].first;
            int new_c = get<1>(top) + directions[i].second;

            if (new_r >= 0 && new_r < n && new_c >= 0 && new_c < m && rows[new_r][new_c] != '#') {
                rows[new_r][new_c] = '#';
                q.push(make_tuple(new_r, new_c, get<2>(top) + dir_chars[i]));
            }
        }
    }

    if (!found) cout << "NO" << '\n';
}