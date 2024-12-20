#include <vector>
using namespace std;

class Solution {
  public:
    bool searchMatrix(vector<vector<int>> &matrix, int target) {
        int n = matrix.size(), m = matrix[0].size();
        int l = 0, r = (n * m) - 1;

        while (l <= r) {
            int mid = l + (r - l / 2); // 1 + 5
            int x = mid / m;
            int y = mid % m;

            if (matrix[x][y] == target) return true;
            if (matrix[x][y] < target) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }

        return false;
    }
};