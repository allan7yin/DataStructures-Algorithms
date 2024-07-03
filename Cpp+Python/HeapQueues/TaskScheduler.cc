#include <ctime>
#include <queue>
#include <utility>
#include <vector>

using namespace std;

class Solution {
public:
  int leastInterval(vector<char> &tasks, int n) {
    // we actually don't really care about the character there
    priority_queue<int> pq;
    vector<int> freq(26, 0);
    queue<pair<int, int>> q;
    int time = 0;

    // populate the frequency map
    for (char &ch : tasks) {
      freq[ch - 'a']++;
    }

    // push those into the pq
    for (int i = 0; i < freq.size(); i++) {
      if (freq[i] != 0) {
        pq.push(freq[i]);
      }
    }

    while (!pq.empty() || !q.empty()) {
      time++;
      if (!pq.empty()) {
        int top = pq.top();
        if (top != 1) {
          q.push(make_pair(top - 1, time + n));
        }
        pq.pop();
      } else {
        time = q.front().second;
      }

      // now, all the tasks that can run again need to be popped, and
      // re-inserted into the heap
      while (!q.empty() && q.front().second == time) {
        pq.push(q.front().first);
        q.pop();
      }
    }
    return time;
  }
};
