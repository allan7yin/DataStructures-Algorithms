#include <vector>
using namespace std;

class Solution {
  public:
    vector<int> spiralOrder(vector<vector<int>> &matrix) {
        vector<int> result;
        int right = matrix[0].size() - 1;
        int left = 0;
        int bot = matrix.size() - 1;
        int top = 0;

        while (bot >= top && left <= right) {
            for (int i = left; i <= right; i++) {
                result.push_back(matrix[top][i]);
            }
            top++;
            if (!(bot >= top && left <= right)) break;

            for (int i = top; i <= bot; i++) {
                result.push_back(matrix[i][right]);
            }
            right--;
            if (!(bot >= top && left <= right)) break;

            for (int i = right; i >= left; i--) {
                result.push_back(matrix[bot][i]);
            }
            bot--;
            if (!(bot >= top && left <= right)) break;

            for (int i = bot; i >= top; i--) {
                result.push_back(matrix[i][left]);
            }
            left++;
        }
        return result;
    }
};