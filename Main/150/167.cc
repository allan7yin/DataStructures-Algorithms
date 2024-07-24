#include <vector>
using namespace std;

class Solution {
public:
  vector<int> twoSum(vector<int> &numbers, int target) {
    int l = 0, r = numbers.size() - 1;

    while (l < r) {
      int sum = numbers[l] + numbers[r];

      if (sum == target)
        return {l + 1, r + 1};
      if (sum < target)
        l++;
      if (sum > target)
        r--;
    }
    return {};
  }
};
