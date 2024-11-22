#include <vector>
using namespace std;

class Solution {
  public:
    vector<int> productExceptSelf(vector<int> &nums) {
        int n = nums.size();
        vector<int> f(n, 1);
        vector<int> b(n, 1);

        for (int i = 1; i < n; i++) {
            f[i] = f[i - 1] * nums[i - 1];
        }

        for (int i = n - 2; i >= 0; i--) {
            b[i] = b[i + 1] * nums[i + 1];
        }
        for (int i = 0; i < n; i++) {
            f[i] *= b[i];
        }
        return f;
    }
};