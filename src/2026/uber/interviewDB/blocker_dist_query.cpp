#include <iostream>
#include <vector>
using namespace std;

/*
You have a matrix containing 3 possible cells:

Robots R
Empty cells O
Blockers X
Another given input is a “query”, consisting of a 4-element integer array, representing the left, right, up and down distances to the closest blocker cell.

To solve the problem you need to find all the robots (their positions) that match this given query.
Note: there is at least a robot that matches the query, and all the edges of the matrix are considered blockers

Example:

Grid:
‘R’ ‘O’ ‘O’ ‘X’ ‘O’
‘O’ ‘R’ ‘O’ ‘X’ ‘O’
‘X’ ‘O’ ‘O’ ‘O’ ‘O’
‘X’ ‘O’ ‘O’ ‘X’ ‘O’
‘O’ ‘O’ ‘O’ ‘R’ ‘O’
Query: [2, 2, 2, 4]
Output: [(1, 1)]
If the query was [1, 3, 1, 2], the output would be [(0,0)].

*/
template <typename T>
void print_vector(const vector<T> &res) {
    for (const auto &val : res) {
        cout << val << " ";
    }
    cout << "\n";
}

vector<vector<int>> find_robots(vector<vector<char>> &grid, vector<int> &query) {
    vector<vector<int>> result;
    int n = grid.size(), m = grid[0].size();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == 'R') {
                // check if this robot is a candidate
                int c_i = i, c_j = j;
                int left = query[0], right = query[1], up = query[2], down = query[3];

                bool left_true = (c_j - left == -1 || ((left <= c_j) && grid[c_i][c_j - left] == 'X'));
                bool right_true = (c_j + right == m || ((c_j + right <= m) && grid[c_i][c_j + right] == 'X'));
                bool up_true = (c_i - up == -1 || ((up <= c_i) && grid[c_i - up][c_j] == 'X'));
                bool down_true = (c_i + down == n || ((c_i + down <= n) && grid[c_i + down][c_j] == 'X'));

                if (left_true && right_true && up_true && down_true) {
                    result.push_back({i, j});
                }
            }
        }
    }

    return result;
}

int main() {
    vector<vector<char>> grid = {
        {'R', 'O', 'O', 'X', 'O'},
        {'O', 'R', 'O', 'X', 'O'},
        {'X', 'O', 'O', 'O', 'O'},
        {'X', 'O', 'O', 'X', 'O'},
        {'O', 'O', 'O', 'R', 'O'}};

    vector<int> query = {1, 3, 1, 2};
    auto res = find_robots(grid, query);
    for (auto &pr : res) {
        print_vector(pr);
    }
}