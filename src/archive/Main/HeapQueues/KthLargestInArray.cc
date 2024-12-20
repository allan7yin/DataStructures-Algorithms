#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
      // maintain a k-sized maxHeap of negatives
      priority_queue<int> pq;
      for (int i = 0; i < nums.size(); i++) {
        pq.push(-nums[i]);
      }

      while (pq.size() > k) {
        pq.pop();
      }
      return -pq.top();
    }
};
