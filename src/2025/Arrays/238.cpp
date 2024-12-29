#include <vector>
using namespace std;

class Solution {
  public:
    vector<int> productExceptSelf(vector<int> &nums) {
        int n = nums.size();
        vector<int> forward(n, 1);
        vector<int> backward(n, 1);

        for (int i = 1; i < n; i++) {
            forward[i] = forward[i - 1] * nums[i - 1];
        }

        for (int i = n - 2; i >= 0; i--) {
            backward[i] = backward[i + 1] * nums[i + 1];
        }

        vector<int> result;
        for (int i = 0; i < n; i++) {
            result.push_back(forward[i] * backward[i]);
        }

        return result;
    }
};

// O(n) time