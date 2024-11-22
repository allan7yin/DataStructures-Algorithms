#include <string>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
    vector<vector<string>> result;

  public:
    vector<vector<string>> solveNQueens(int n) {
        unordered_set<int> cols;
        unordered_set<int> bl_tr;
        unordered_set<int> br_tl;

        vector<vector<string>> board(n, vector<string>(n, "."));
        f(board, n, cols, bl_tr, br_tl, 0);
        return result;
    }

    void f(vector<vector<string>> &board, int n, unordered_set<int> &cols, unordered_set<int> &br_tl,
           unordered_set<int> &bl_tr, int r) {
        if (r >= n) {
            vector<string> compress;
            for (auto &row : board) {
                string temp = "";
                for (auto &sq : row) {
                    temp += sq;
                }
                compress.push_back(temp);
            }
            result.push_back(compress);
        }

        for (int c = 0; c < n; c++) {
            // try every column
            if (cols.find(c) == cols.end() && br_tl.find(r - c) == br_tl.end() && bl_tr.find(r + c) == bl_tr.end()) {
                // means this column is available
                board[r][c] = "Q";
                cols.insert(c);
                br_tl.insert(r - c);
                bl_tr.insert(r + c);
                f(board, n, cols, br_tl, bl_tr, r + 1);
                cols.erase(c);
                br_tl.erase(r - c);
                bl_tr.erase(r + c);
                board[r][c] = ".";
            }
        }
    }
};