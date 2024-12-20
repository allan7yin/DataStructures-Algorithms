#include <vector>

using namespace std;

class Solution {
  public:
    // should be just be a simple DFS
    bool exist(vector<vector<char>> &board, string word) {
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                if (board[i][j] == word[0] && f(board, i, j, word, 0)) {
                    return true;
                }
            }
        }
        return false;
    }

    bool f(vector<vector<char>> &board, int i, int j, string word, int idx) {
        if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size() || board[i][j] != word[idx]) {
            return false;
        } else if (idx == word.size() - 1) {
            return true;
        }

        // not visited before
        bool result = false;
        char temp = board[i][j];
        board[i][j] = '#';
        result = result || f(board, i + 1, j, word, idx + 1);
        result = result || f(board, i - 1, j, word, idx + 1);
        result = result || f(board, i, j + 1, word, idx + 1);
        result = result || f(board, i, j - 1, word, idx + 1);
        board[i][j] = temp;
        return result;
    }
};