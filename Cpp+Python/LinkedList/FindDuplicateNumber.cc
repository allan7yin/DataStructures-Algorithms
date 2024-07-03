#include <vector>
using namespace std;

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow = 0, fast = 0;
        while (true) {
            slow = nums[slow];
            fast = nums[nums[fast]];
            if (slow == fast) {
                break;
            }
        }

        // move slow to the beginning 
        slow = 0;
        while (true) {
            slow = nums[slow];
            fast = nums[fast];
            if (slow == fast) {
                break;
            }
        }
        return slow;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1,3,4,2,2};
    sol.findDuplicate(nums);
}