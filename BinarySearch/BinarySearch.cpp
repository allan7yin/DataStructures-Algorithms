#include <vector>

using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        return dnc(nums, target, 0, nums.size()-1);
    }

    int dnc(vector<int> &nums, int target, int start, int end) {
        if (end >= start) {
            int med = start + (end-start)/2;
            if (nums[med] == target) {
                return med;
            }
        
            if (target <= nums[med]) {
                return dnc(nums, target, start, med-1);
            }
            return dnc(nums, target, med + 1, end);
        }
        return -1;
    }
};

int main() {}