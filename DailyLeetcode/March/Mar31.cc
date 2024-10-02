#include <vector>
using namespace std;

class Solution {
public:
  long long countSubarrays(vector<int> &nums, int minK, int maxK) {
    int mini = -1, maxi = -1;
    int leftIndex = 0;
    long long count = 0;

    for (int i = 0; i < nums.size(); i++) {
      if (nums[i] < minK || nums[i] > maxK) {
        mini = -1;
        maxi = -1;
        leftIndex = i + 1;
      }

      if (nums[i] == minK) {
        mini = i;
      }

      if (nums[i] == maxK) {
        maxi = i;
      }

      count += max(0, min(mini, maxi) - leftIndex + 1);
    }
    return count;
  }
};
