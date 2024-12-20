#include <vector>
using namespace std;

/*
maintain a min subarray and a max one so far
-> [2,3,-2,4]
-> [-4,-3,-2]
-> [2,-1,1,1]
*/
class Solution {
  public:
    int maxProduct(vector<int> &nums) {
        if (nums.size() == 1) return nums[0];
        int maxProd = nums[0];
        int movingMax = nums[0];
        int movingMin = nums[0];

        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] > 0) {
                movingMax = max(nums[i], movingMax * nums[i]);
                movingMin = min(nums[i], movingMin * nums[i]);
            } else {
                int old = movingMax;
                movingMax = max(nums[i], movingMin * nums[i]);
                movingMin = min(nums[i], old * nums[i]);
            }
            maxProd = max(maxProd, movingMax);
        }
        return maxProd;
    }
};
