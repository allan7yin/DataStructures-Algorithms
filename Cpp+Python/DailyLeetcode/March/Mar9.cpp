#include <vector>
using namespace std;

class Solution {
public:
  int getCommon(vector<int> &nums1, vector<int> &nums2) {
    int result = -1;

    int l1 = 0, l2 = 0;
    while (l1 < nums1.size() && l2 < nums2.size()) {
      if (nums1[l1] == nums2[l2]) {
        result = nums1[l1];
        break;
      } else if (nums1[l1] > nums2[l2]) {
        l2++;
      } else {
        l1++;
      }
    }
    return result;
  }
};
