#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
      priority_queue<int> pq(stones.begin(), stones.end());

      while (pq.size() > 1) {
        int top = pq.top();
        pq.pop();
        int top2 = pq.top();
        pq.pop();

        if (top != top2) {
          pq.push(abs(top-top2));
        }
      }
      return pq.empty() ? 0 : pq.top();
    }
};
