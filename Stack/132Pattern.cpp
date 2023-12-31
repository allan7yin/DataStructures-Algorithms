#include <vector>
#include <utility>

using namespace std;

/*
    - maintain a decreasing monotonic stack, where each stack entry remebers its value and the mininimum value that came before it 
*/
class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        vector<pair<int, int>> stack;
        int minValue = nums[0];
        for (int i = 0; i < nums.size(); i++) {
            while (!stack.empty() && nums[i] >= stack.back().first) {
                stack.pop_back();
            }

            if (!stack.empty() && stack.back().second < nums[i]) {
                return true;
            } else {
                stack.push_back(make_pair(nums[i], minValue));
                minValue = min(minValue, nums[i]);
            }
        }
        return false;
    }
};

int main() {}