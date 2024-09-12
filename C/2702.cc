#include <vector>
using namespace std;

class Solution {
  public:
    bool possible(vector<int> &nums, int k, long x, long y) {
        long ops = 0;
        // see if we can get everthing <= 0 with k operations
        for (auto &num : nums) {
            if (num > (y * k)) {
                // need other operations
                ops += (ceil((double)(num - (y * k)) / (double)(x - y)));
            }
        }
        return ops <= k;
    }

    int minOperations(vector<int> &nums, int x, int y) {
        // need to binary search for this problem
        int least = 0, most = *(max_element(nums.begin(), nums.end()));
        while (least < most) {
            int mid = least + (most - least) / 2;
            if (possible(nums, mid, x, y)) {
                most = mid;
            } else {
                least = mid + 1;
            }
        }
        return least;
    }
};
