#include <unordered_map>
#include <utility>
#include <vector>

// this solution still TLE'S!!!!!
class Solution {
public:
  long long maximumTotalCost(std::vector<int> &nums) {
    // Using a map to memoize results. The key is a pair of (index, sign).
    std::unordered_map<std::pair<int, int>, long long, pair_hash> memo;
    return recurse(nums, 0, 1, memo);
  }

private:
  // be really familiar with implementing your own hash function -> unordered_map not supporting pairs is annoying
  struct pair_hash {
    template <class T1, class T2>
    std::size_t operator()(const std::pair<T1, T2> &pair) const {
      return std::hash<T1>()(pair.first) ^ std::hash<T2>()(pair.second);
    }
  };

  long long recurse(std::vector<int> &nums, int I, int s, std::unordered_map<std::pair<int, int>, long long, pair_hash> &memo) {
    // Check if the result for this state is already computed
    auto key = std::make_pair(I, s);
    if (memo.find(key) != memo.end()) {
      return memo[key];
    }

    // Base case: if we've processed all elements
    if (I >= nums.size()) {
      return 0;
    }

    // Recursive case: compute the value
    long long result = s * nums[I] + std::max(recurse(nums, I + 1, 1, memo), recurse(nums, I + 1, -s, memo));

    // Memoize the result before returning
    memo[key] = result;
    return result;
  }
};