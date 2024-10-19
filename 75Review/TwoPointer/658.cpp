#include <queue>
#include <vector>
using namespace std;

class Solution {
  public:
    vector<int> findClosestElements(vector<int> &arr, int k, int x) {
        priority_queue<int, vector<int>, greater<int>> pq;
        for (int &num : arr) {
            if (pq.size() == k) {
                int diff = abs(num - x);
                if (diff < abs(pq.top() - x)) {
                    // this is smaller, pop and add this
                    pq.pop();
                    pq.push(num);
                }
            } else {
                pq.push(num);
            }
        }

        vector<int> result;
        while (!pq.empty()) {
            result.push_back(pq.top());
            pq.pop();
        }
        return result;
    }
};

// 1 2 3 4 5
// k = 2, x = 4