#include <string>
#include <vector>
using namespace std;

class Solution {
    bool gameOver = false;

  public:
    int adjacentRevealedMines(vector<vector<char>> &board, int r, int c) {
        int count = 0;
        int max_r = board.size();
        int max_c = board[0].size();

        // Check top
        if (r > 0 && board[r - 1][c] == 'M') {
            count++;
        }
        // Check bottom
        if (r < max_r - 1 && board[r + 1][c] == 'M') {
            count++;
        }
        // Check left
        if (c > 0 && board[r][c - 1] == 'M') {
            count++;
        }
        // Check right
        if (c < max_c - 1 && board[r][c + 1] == 'M') {
            count++;
        }
        // Check top-left
        if (r > 0 && c > 0 && board[r - 1][c - 1] == 'M') {
            count++;
        }
        // Check top-right
        if (r > 0 && c < max_c - 1 && board[r - 1][c + 1] == 'M') {
            count++;
        }
        // Check bottom-left
        if (r < max_r - 1 && c > 0 && board[r + 1][c - 1] == 'M') {
            count++;
        }
        // Check bottom-right
        if (r < max_r - 1 && c < max_c - 1 && board[r + 1][c + 1] == 'M') {
            count++;
        }

        return count;
    }

    void f(vector<vector<char>> &board, int r, int c) {
        if (gameOver || r < 0 || r >= board.size() || c < 0 || c >= board[0].size()) return;
        // we are revealing cell r, c
        if (board[r][c] == 'M') {
            board[r][c] = 'X';
            return;
        }

        int adj = adjacentRevealedMines(board, r, c);

        if (board[r][c] == 'E' && adj == 0) {
            board[r][c] == 'B';
            // ecurse
            f(board, r + 1, c);
            f(board, r - 1, c);
            f(board, r, c + 1);
            f(board, r, c - 1);
        }

        if (board[r][c] == 'E' && adj >= 1) {
            board[r][c] = to_string(adj)[0];
        }
    }

    vector<vector<char>> updateBoard(vector<vector<char>> &board, vector<int> &click) {
        // click is the beinning
        f(board, click[0], click[1]);
        return board;
    }
};