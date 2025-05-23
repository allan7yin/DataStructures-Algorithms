#include "../bits/stdc++.h"

using namespace std;

/*
trick is to hash each square to some key to make sure unique. That is:
- just have a hashmap for rows, columns, and quadrants
- hash int to unordered_set<int>

- constant time with respect to the input size (input size is MN, and runtime is MN) -> O(1)
*/

class Solution {
  public:
    bool isValidSudoku(vector<vector<char>> &board) {
        unordered_map<int, unordered_set<char>> rows;
        unordered_map<int, unordered_set<char>> cols;
        unordered_map<int, unordered_set<char>> quads;

        bool valid = true;
        for (int r = 0; r < 9; r++) {
            for (int c = 0; c < 9; c++) {
                if (board[r][c] == '.') continue;
                if (rows[r].count(board[r][c]) || cols[c].count(board[r][c]) || quads[10 * (r / 3) + (c / 3)].count(board[r][c])) valid = false;

                rows[r].insert(board[r][c]);
                cols[c].insert(board[r][c]);
                quads[10 * (r / 3) + (c / 3)].insert(board[r][c]);
            }
        }

        return valid;
    }
};
