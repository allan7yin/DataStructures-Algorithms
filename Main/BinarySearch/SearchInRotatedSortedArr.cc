#include <vector>

using namespace std;

/*
    - consider the array [0,1,2,4,5,6,7]
    - has been rotated: [4,5,6,7,0,1,2]
    - for each sub-problem, the array is either sorted or contains the segment breaking from 
    - last index to first index 

*/

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0, r = nums.size()-1;
        int result = -1;
        while (l <= r) {
            int mid = l + (r-l)/2;
            if (nums[mid] == target) {
                result = mid;
                break;
            }

            if (nums[l] <= nums[mid]) {
                // left half is sorted 
                if (target >= nums[l] && target <= nums[mid]) {
                    r = mid - 1;
                } else {
                    l = mid + 1;
                }
            } else {
                // means the right half is sorted 
                if (target <= nums[r] && target >= nums[mid]) {
                    l = mid + 1;
                } else {
                    r = mid - 1;
                }
            }
        }
        return result;
    }
};


int main () {}