#include <vector>
#include <queue>
using namespace std;

class KthLargest {
    priority_queue<int> pq;
    int k;
public:
    KthLargest(int k, vector<int>& nums) {
        for (int i = 0; i < nums.size(); i++) {
            pq.push(-nums[i]);
        }
        this->k = k;

        // trim the pq into size k
        while (pq.size() > k) {
            pq.pop();
        }
    }
    
    int add(int val) {
        pq.push(-val);
        if (pq.size() > k) {
            pq.pop();
        }
        return pq.top() * -1;
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */
