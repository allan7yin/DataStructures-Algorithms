#include <unordered_map>
#include <vector>
using namespace std;

/*
523. Continuous Subarray Sum

This problem, and important thing to remeber is that say we have an array nums.
When working with a modulo k, if two prefix sums have the same remainder when
divided by k, the elements between these two prefix sums sum up to a multiple of
k

So, we add the earliest index seen for a certain prefix, and if we see it again,
we know we have subarray that sums to multiple of k

Review this -> prefix sum + hashmap is a very common pattern for solving
subarray problem
*/

class Solution {
public:
  bool checkSubarraySum(vector<int> &nums, int k) {
    // array to record current sum, from index 0 to index i
    if (nums.size() < 2)
      return false;
    vector<int> sums(nums.size(), 0);
    unordered_map<int, int> mod_k;
    mod_k[0] = -1;
    int prefix = 0;

    for (int i = 0; i < nums.size(); i++) {
      prefix += nums[i];
      prefix %= k;

      if (mod_k.count(prefix) && i > mod_k[prefix] + 1) {
        return true;
      }
      if (mod_k.find(prefix) == mod_k.end()) {
        mod_k[prefix] = i;
      }
    }
    return false;
  }
};
