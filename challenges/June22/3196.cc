#include <unordered_map>
#include <utility>
#include <vector>

class Solution {
public:
  //  O(1) space
  long long maximumTotalCost(std::vector<int> &nums) {
    int n = nums.size();
    long long prev_pos_flip = LLONG_MIN;
    long long prev_pos_noflip = nums[0];

    for (int i = 1; i < nums.size(); i++) {
      long long current_no_flip = nums[i] + std::max(prev_pos_noflip, prev_pos_flip);
      long long current_flip = prev_pos_noflip - nums[i];

      prev_pos_flip = current_flip;
      prev_pos_noflip = current_no_flip;
    }
    return std::max(prev_pos_flip, prev_pos_noflip);
  }

  // O(n) space
  // long long maximumTotalCost(vector<int>& nums) {
  //     int n = nums.size();
  //     std::vector<std::vector<long long>> dp(n, std::vector<long long>(2, LLONG_MIN));
  //     dp[0][0] = nums[0];

  //     for (int i = 1; i < nums.size(); i++) {
  //         dp[i][0] = nums[i] + max(dp[i-1][0], dp[i-1][1]);
  //         dp[i][1] = dp[i-1][0] - nums[i];
  //     }
  //     return max(dp[n-1][1], dp[n-1][0]);
  // }
};

// this solution still TLE'S!!!!!
// class Solution {
// public:
//   long long maximumTotalCost(std::vector<int> &nums) {
//     // Using a map to memoize results. The key is a pair of (index, sign).
//     std::unordered_map<std::pair<int, int>, long long, pair_hash> memo;
//     return recurse(nums, 0, 1, memo);
//   }

// private:
//   // be really familiar with implementing your own hash function -> unordered_map not supporting pairs is annoying
//   struct pair_hash {
//     template <class T1, class T2>
//     std::size_t operator()(const std::pair<T1, T2> &pair) const {
//       return std::hash<T1>()(pair.first) ^ std::hash<T2>()(pair.second);
//     }
//   };

//   long long recurse(std::vector<int> &nums, int I, int s, std::unordered_map<std::pair<int, int>, long long, pair_hash> &memo) {
//     // Check if the result for this state is already computed
//     auto key = std::make_pair(I, s);
//     if (memo.find(key) != memo.end()) {
//       return memo[key];
//     }

//     // Base case: if we've processed all elements
//     if (I >= nums.size()) {
//       return 0;
//     }

//     // Recursive case: compute the value
//     long long result = s * nums[I] + std::max(recurse(nums, I + 1, 1, memo), recurse(nums, I + 1, -s, memo));

//     // Memoize the result before returning
//     memo[key] = result;
//     return result;
//   }
// };