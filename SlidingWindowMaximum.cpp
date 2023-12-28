#include <deque>
#include <vector>

using namespace std;
/*
    - say our deque is something like [1,2,4,6,19] -> this is monotonoically decreasing 
    - the front of this is front and the back is back 

*/

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        // monotonically decreasing dequeue 
        deque<int> q;
        vector<int> sol;
        int l = 0;
        for (int r = 0; r < nums.size(); r++) {
            while (!q.empty() && nums[r] > nums[q.back()]) {
                // pop everything 
                q.pop_back();
            }
            q.push_back(r);

            // this is moving the sliding window 
            if (l > q.front()) {
                q.pop_front();
            }

            if (r+1 >= k) {
                sol.push_back(nums[q.front()]);
                l++;
            }
        }
        return sol;
        
    }
};

int main() {}