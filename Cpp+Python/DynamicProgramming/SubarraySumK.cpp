#include <unordered_map>
#include <vector>
using namespace std;

/*
 * This is a prefix-sum type of problem
 * https://www.youtube.com/watch?v=fFVZt-6sgyo
 *
 * The point is, we keep track of prefix sums, so that when the current
 * sub-array sum reaches a value, say x, and we know there is a prefix that sums
 * to k - x, then we know that the combined
 *
 * - Check obsidian notes for this
 */

class Solution {
public:
  int subarraySum(vector<int> &nums, int k) {
    unordered_map<int, int> prefix_sum_count;
    prefix_sum_count[0] = 1;

    int sum = 0;
    int count = 0;
    for (int &num : nums) {
      sum += num;
      int distance = sum - k;

      if (prefix_sum_count.find(distance) != prefix_sum_count.end()) {
        count += prefix_sum_count[distance];
      }
      prefix_sum_count[sum]++;
    }
    return count;
  }
};
