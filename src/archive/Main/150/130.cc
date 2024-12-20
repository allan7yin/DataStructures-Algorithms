#include <vector>
using namespace std;

class Solution {
    int n;
    int m;

  public:
    void f(vector<vector<char>> &board, int r, int c, char replacement) {
        if (r < 0 || r >= n || c < 0 || c >= m || board[r][c] != 'O') return;
        // current square is '0' -> change
        board[r][c] = replacement;
        f(board, r + 1, c, replacement);
        f(board, r - 1, c, replacement);
        f(board, r, c + 1, replacement);
        f(board, r, c - 1, replacement);
    }
    void solve(vector<vector<char>> &board) {
        n = board.size();
        m = board[0].size();
        // dfs on every border square
        for (int i = 0; i < n; i++) {
            f(board, i, 0, 'T');
            f(board, i, m - 1, 'T');
        }

        for (int i = 0; i < m; i++) {
            f(board, 0, i, 'T');
            f(board, n - 1, i, 'T');
        }

        // now border ones taken care of, do it for the rest
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (board[i][j] == 'O') f(board, i, j, 'X');
            }
        }

        // now, revert all the T's
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (board[i][j] == 'T') board[i][j] = 'O';
            }
        }
    }
};
