#include <queue>
#include <vector>

using namespace std;

/*
Of course, we want to schedule most frequent tasks as soon as possible
["A","A","A","B","B","B"]

the trick is => we will use a pq to keep track of the ready tasks, to get the most frequent one
then we will use a queue to keep track of when tasks are ready to be popped
*/
class Solution {
  public:
    int leastInterval(vector<char> &tasks, int n) {
        // compute frequency map
        priority_queue<int> pq;
        queue<pair<int, int>> q; // freq, finish time
        unordered_map<char, int> mp;
        for (auto &task : tasks) {
            mp[task]++;
        }

        for (auto &kv : mp) {
            pq.push(kv.second);
        }

        int time = 0;
        while (!pq.empty() || !q.empty()) {
            time++;
            if (!pq.empty()) {
                // can do this task
                int top = pq.top();
                if (top > 1) {
                    q.push({top - 1, time + n});
                }
                pq.pop();
            } else {
                // nothing is available, move the time to the next one, a.k.a time of first in queue
                time = q.front().second;
            }

            while (!q.empty() && q.front().second <= time) {
                pq.push(q.front().first);
                q.pop();
            }
        }

        return time;
    }
};