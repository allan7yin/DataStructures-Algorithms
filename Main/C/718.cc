#include <vector>
using namespace std;

class Solution {
  public:
    int findLength(vector<int> &nums1, vector<int> &nums2) {
        int maxLength = 0;
        int dp[1001][1001];
        memset(dp, 0, sizeof(dp));

        for (int i = nums1.size() - 1; i >= 0; i--) {
            for (int j = nums2.size() - 1; j >= 0; j--) {
                if (nums1[i] == nums2[j]) {
                    dp[i][j] = 1 + dp[i + 1][j + 1];
                }
                maxLength = max(maxLength, dp[i][j]);
            }
        }
        return maxLength;
    }
};