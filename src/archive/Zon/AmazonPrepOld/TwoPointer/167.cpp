#include <vector>

using namespace std;

class Solution {
  public:
    vector<int> twoSum(vector<int>& numbers, int target) {
      int l = 0, r = numbers.size() - 1;
      vector<int> result;
      while (l <= r) {
        if (numbers[l] + numbers[r] == target) {
          result = {l + 1, r + 1};
          break;
        } else if (numbers[l] + numbers[r] < target) {
          l++;
        } else {
          r--;
        }
      }
      return result;
    }
};
