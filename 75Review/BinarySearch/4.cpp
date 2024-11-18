#include <vector>
 
using namespace std;

class Solution {
public:
  double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2) {
    int n = nums1.size();
    int m = nums2.size();

    if (n > m) return findMedianSortedArrays(nums2, nums1);

    int l = 0, r = n;
    while (l <= r) {
      int i = l + (r - l) / 2;
      int j = (n + m + 1) / 2 - i;

      int left1 = (i > 0) ? nums1[i - 1] : INT_MIN;
      int left2 = (j > 0) ? nums2[j - 1] : INT_MIN;
      int right1 = (i < n) ? nums1[i] : INT_MAX;
      int right2 = (j < m) ? nums2[j] : INT_MAX;

      if (left1 <= right2 && left2 <= right1) {
        if ((n + m)% 2 == 0) {
          return (max(left1, left2) + min(right1, right2)) / 2.0;
        } else {
          return max(left1, left2);
        }
      } else if (left1 > right2) {
        r = i - 1;
      } else {
        l = i + 1;
      }
    }

    return 0;
  }
};
