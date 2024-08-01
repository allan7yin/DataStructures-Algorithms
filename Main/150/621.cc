#include <queue>
#include <vector>

using namespace std;

class Solution {
  public:
    int leastInterval(vector<char> &tasks, int n) {
        // minheap of freq, as we most freq to run as early as possible
        priority_queue<int> pq;
        queue<pair<int, int>> q;     // freq, finish
        unordered_map<char, int> mp; // map the task to the count of it

        for (char &task : tasks) {
            mp[task]++;
        }

        for (auto &kv : mp) {
            pq.push(kv.second);
        }

        int time = 0;
        while (!q.empty() || !pq.empty()) {
            time++;
            if (!pq.empty()) {
                int top = pq.top();
                if (top > 1) q.push({top - 1, time + n});
                pq.pop();
            } else {
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