#include <vector>
using namespace std;

class Solution {
public:
  vector<int> productExceptSelf(vector<int> &nums) {
    // 2 loops
    int n = nums.size();
    vector<int> result(n, 1);
    for (int i = 0; i < n - 1; i++) {
      result[i + 1] = result[i] * nums[i];
    }

    // 1 1 2 6
    int temp = 1;
    for (int i = n - 1; i > 0; i--) {
      temp *= nums[i];
      result[i - 1] *= temp;
    }

    return result;
  }
};
