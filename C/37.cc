#include <cstring>
#include <vector>
using namespace std;

bool cols[10][10];
bool rows[10][10];
bool batches[10][10];

class Solution {
  public:
    // recursive step function
    bool f(vector<vector<char>> &board, int r, int c) {
        // check each integer in 1 - 9
        if (c == 9) {
            c = 0;
            r++;
            if (r == 9) return true;
        }

        if (board[r][c] != '.') {
            // means there is something in this square, move on
            return f(board, r, c + 1);
        }

        int pos = (r / 3) * 3 + c / 3;
        // else, we are on a square that can be filled
        for (char i = '1'; i <= '9'; i++) {
            int numIndex = i - '1';
            if (!cols[c][numIndex] && !rows[r][numIndex] && !batches[pos][numIndex]) {
                board[r][c] = i;
                cols[c][numIndex] = true;
                rows[r][numIndex] = true;
                batches[pos][numIndex] = true;

                if (f(board, r, c + 1)) {
                    return true;
                }
                // backtrack
                cols[c][numIndex] = false;
                rows[r][numIndex] = false;
                batches[pos][numIndex] = false;
                board[r][c] = '.';
            }
        }
        return false;
        ;
    }
    void solveSudoku(vector<vector<char>> &board) {
        int n = board.size();
        memset(cols, false, sizeof(cols));
        memset(rows, false, sizeof(rows));
        memset(batches, false, sizeof(batches));
        // solve this problem with a backtracking approach
        // first, iterate through the grid and add the already in place values
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] != '.') {
                    int numIndex = board[i][j] - '1'; // Convert '1'-'9' to 0-8
                    cols[j][numIndex] = true;
                    rows[i][numIndex] = true;
                    batches[(i / 3) * 3 + j / 3][numIndex] = true;
                }
            }
        }

        // now, iterate through and recurse
        f(board, 0, 0);
    }
};