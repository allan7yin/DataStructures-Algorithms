#include <queue>
#include <vector>

using namespace std;

class KthLargest {
    priority_queue<int, vector<int>, greater<int>> mh;
    int k = 0;

  public:
    KthLargest(int k, vector<int> &nums) {
        this->k = k;
        for (int &num : nums) {
            mh.push(num);
        }

        while (mh.size() > k) {
            mh.pop();
        }
    }

    int add(int val) {
        mh.push(val);
        if (mh.size() > k) mh.pop();
        return mh.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */

// 4 5 8 2 -> 4 5 8