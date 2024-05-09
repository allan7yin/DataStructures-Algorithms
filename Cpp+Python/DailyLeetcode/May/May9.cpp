#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

// sorry, the smarter way is to just sort it and then take the first k elements
// lol
class Solution {
public:
  long long maximumHappinessSum(vector<int> &happiness, int k) {
    long long happiness_count = 0;
    priority_queue<int> pq(happiness.begin(), happiness.end());

    int decrement_count = 0;

    for (int i = 0; i < k; i++) {
      if (!pq.empty()) {
        int top = max(pq.top() - decrement_count, 0);
        pq.pop();

        decrement_count++;
        happiness_count += top;
      }
    }
    return happiness_count;
  }
};
