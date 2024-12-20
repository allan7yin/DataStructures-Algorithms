#include <vector>

using namespace std;
/*
    - find the mid value -> we keep track of l and r pointer
    - if nums[r] > nums[l], means this segment is sorted, nums[l] may be minimum element, and will handle if nums is aleready sorted 
    - compute mid. If nums[mid] > nums[l], then if already sorted, handled. Other instance, is min element is in the right, so l = mid + 1
*/
class Solution {
public:
    int findMin(vector<int>& nums) {
        int l = 0, r = nums.size() - 1;
        int result = nums[0];
        while (l <= r) {
            int mid = l + (r-l)/2;
            if (nums[r] > nums[l]) {
                result = min(result, nums[l]);
                break;
            }
            result = min(result, nums[mid]);
            if (nums[mid] >= nums[l]) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        return result;
    }
};

int main() {}