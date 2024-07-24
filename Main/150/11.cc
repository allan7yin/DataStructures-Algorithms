#include <vector>
using namespace std;

// kind of greedy, we just move the pointer of less height
class Solution {
public:
  int maxArea(vector<int> &height) {
    int l = 0, r = height.size() - 1;
    int maxv = 0;
    while (l < r) {
      maxv = max(maxv, (r - l) * min(height[l], height[r]));
      if (height[l] < height[r]) {
        l++;
      } else {
        r--;
      }
    }
    return maxv;
  }
};
