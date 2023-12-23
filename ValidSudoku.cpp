#include <vector>
#include <map>
#include <unordered_set>

using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int n = board.size();
        unordered_map<int, unordered_set<int>> row;
        unordered_map<int, unordered_set<int>> col;
        unordered_map<int, unordered_set<int>> sqr;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == '.') continue;
                if ((row[i].count(board[i][j]) > 0) ||  (col[j].count(board[i][j]) > 0) || (sqr[10*(i/3) + (j/3)].count(board[i][j]) > 0)) {
                    return false;
                }
                row[i].insert(board[i][j]);
                col[j].insert(board[i][j]);
                sqr[10*(i/3) + (j/3)].insert(board[i][j]);
            }
        }
        return true;
    }
};

int main() {}