#include <vector>
using namespace std;

class Solution {
  public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> dp(n, vector<int>(n));
        int count = 1;
        int left = 0, right = n - 1;
        int top = 0, bottom = n - 1;
        while (left <= right && top <= bottom) {
            for (int i = left; i <= right; i++) {
                dp[top][i] = count;
                count++;
            }
            top++;
            for (int i = top; i <= bottom; i++) {
                dp[i][right] = count;
                count++;
            }
            right--;
            if (top <= bottom) {
                for (int i = right; i >= left; i--) {
                    dp[bottom][i] = count;
                    count++;
                }
                bottom--;
            }

            if (left <= right) {
                for (int i = bottom; i >= top; i--) {
                    dp[i][left] = count;
                    count++;
                }
                left++;
            }
        }
        return dp;
    }
};
