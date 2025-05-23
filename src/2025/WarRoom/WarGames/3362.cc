#include "../bits/stdc++.h"

class Solution {
  public:
    int maxRemoval(vector<int> &nums, vector<vector<int>> &queries) {
        sort(queries.begin(), queries.end(), [](const auto &a, const auto &b) {
            return a[0] < b[0];
        });

        priority_queue<int, vector<int>, greater<int>> active; // MIN heap
        priority_queue<int> ready;

        int index = 0;
        for (int i = 0; i < nums.size(); i++) {
            // check if any query ranges have expired
            while (!active.empty() && active.top() < i) {
                active.pop();
            }

            // while we can, push the ready ones
            while (index < queries.size() && queries[index][0] <= i) {
                ready.push(queries[index][1]);
                index++;
            }

            // see if we can push anything from the ready queue into the active queue
            while (nums[i] > active.size()) {
                if (ready.empty() || ready.top() < i) {
                    return -1;
                }

                active.push(ready.top());
                ready.pop();
            }
        }

        return ready.size();
    }
};