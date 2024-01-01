#include <vector>

using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        return dnc(matrix, target, 0, matrix[0].size() * matrix.size() - 1);
    }

    bool dnc(vector<vector<int>> &matrix, int target, int start, int end) {
        if (end >= start){
            int med = start + (end - start)/2;
            int row = med / matrix[0].size();
            int col = med % matrix[0].size();
            if (matrix[row][col] == target) {
                return true;
            }

            if (target < matrix[row][col]) {
                return dnc(matrix, target, start, row*matrix[0].size() + col - 1);
            }
            return dnc(matrix, target, row*matrix[0].size() + col + 1, end);
        }

        return false;
    }
};

int main() {
    Solution sol;
        std::vector<std::vector<int>> matrix = {
        {1, 3, 5, 7},
        {10, 11, 16, 20},
        {23, 30, 34, 60}
    };
    sol.searchMatrix(matrix,3);
}