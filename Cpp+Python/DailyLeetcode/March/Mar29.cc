#include <algorithm>
#include <vector>

using namespace std;
/*
- this essentially comes down to finding every k wide window
- then, take length of left side + 1 multiplied by length of right side + 1
- lol, guess this beats 95.35% of solutions
- posted a solution for this LOL: https://leetcode.com/problems/count-subarrays-where-max-element-appears-at-least-k-times/solutions/4939984/solution-explanation-o-n-runtime-and-o-1-space/
*/
class Solution {
public:
  long long countSubarrays(vector<int> &nums, int k) {
    // find the max value, need long long
    long long count = 0;
    int maxValue = 0;
    int maxValueCount = 0;
    for (int &num : nums) {
      maxValue = max(maxValue, num);
    }

    // now that we know max value, find first k-wide window
    int leftFlag = 0;
    int l = 0;
    for (int r = 0; r < nums.size(); r++) {
      if (nums[r] == maxValue) {
        maxValueCount++;
      }

      if (maxValueCount == k) {
        // first move left pointer to this right most index
        while (nums[l] != maxValue) {
          l++;
        }
        // add to count
        count += ((l - leftFlag + 1) * ((nums.size() - 1) - r + 1));
        l++;
        leftFlag = l;
        maxValueCount--;
      }
    }
    return count;
  }
};