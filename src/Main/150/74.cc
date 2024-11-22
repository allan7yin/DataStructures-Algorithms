#include <vector>
using namespace std;

class Solution {
public:
  bool searchMatrix(vector<vector<int>> &matrix, int target) {
    int rows = matrix.size();
    if (rows == 0)
      return false;
    int cols = matrix[0].size();

    int l = 0,
        r = (rows * cols) - 1; // l and r should start at 0 and (rows*cols - 1)
    while (l <= r) {
      int m = (l + r) / 2;
      int m_r = m / cols;
      int m_c = m % cols;

      if (matrix[m_r][m_c] == target)
        return true;
      if (matrix[m_r][m_c] < target) {
        l = m + 1;
      } else {
        r = m - 1;
      }
    }
    return false;
  }
};
