#include <queue>
#include <vector>
using namespace std;

/*
Idea: Want tasks sorted by their frequency
- build vector of pairs of frequencies, sort by second parameter
- should be straight forward from there

A: 6
B: 1
C: 1
D: 1
E: 1
F: 1
G: 1

- the above makes this idea incorrect: consider using maxHeap
- we'll push the top of heap into a queue as a pair: (freq, time of release)
- each unit of time, we pop all that we can from the top of the queue
- if we can't and heap is empty -> idle
- we don't really care what the character is -> just the frequency
*/
class Solution {
public:
  int leastInterval(vector<char> &tasks, int n) {
    int m = tasks.size();
    priority_queue<int> maxHeap;
    queue<pair<int, int>> q;

    // create vector of these pairs, and push them into heap
    vector<int> freq(26, 0);
    for (char &ch : tasks) {
      freq[ch - 'A']++;
    }
    for (int i = 0; i < 26; i++) {
      if (freq[i] != 0) {
        maxHeap.push(freq[i]);
      }
    }

    // now, we
    int time = 0;
    while (!q.empty() || !maxHeap.empty()) {
      time++;
      // pop top from the maxHeap
      if (!maxHeap.empty()) {
        int top = maxHeap.top();
        top--;
        maxHeap.pop();
        if (top != 0) {
          q.push({top, time + n});
        }
      } else {
        time = q.front().second;
      }

      while (!q.empty() && q.front().second == time) {
        maxHeap.push(q.front().first);
        q.pop();
      }
    }
    return time;
  }
};