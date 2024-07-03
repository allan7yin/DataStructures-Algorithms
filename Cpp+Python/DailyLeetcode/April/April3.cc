#include <vector>
using namespace std;

// should be a basic dfs problem
class Solution {
public:
  bool exist(vector<vector<char>> &board, string word) {
    for (int r = 0; r < board.size(); r++) {
      for (int c = 0; c < board[0].size(); c++) {
        if (dfs(board, word, 0, r, c)) {
          return true;
        }
      }
    }
    return false;
  }

  bool dfs(vector<vector<char>> &board, string word, int index, int row, int col) {
    if (index == word.size()) {
      return true;
    }
    if (
        col < 0 ||
        col >= board[0].size() ||
        row < 0 ||
        row >= board.size() ||
        board[row][col] != word[index]) {
      return false;
    }

    board[row][col] = '#';

    bool cond = (dfs(board, word, index + 1, row, col + 1) ||
                 dfs(board, word, index + 1, row, col - 1) ||
                 dfs(board, word, index + 1, row + 1, col) ||
                 dfs(board, word, index + 1, row - 1, col));

    board[row][col] = word[index];
    return cond;
  }
};