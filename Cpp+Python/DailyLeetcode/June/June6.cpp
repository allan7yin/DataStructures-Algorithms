#include <queue>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
  bool isNStraightHand(vector<int> &hand, int groupSize) {
    if (hand.size() % groupSize != 0) {
      return false;
    }

    unordered_map<int, int> count;
    priority_queue<int, vector<int>, greater<int>> minHeap;
    for (int &num : hand) {
      count[num]++;
    }

    for (auto &kv : count) {
      minHeap.push(kv.first);
    }

    // now that we have frequency map, we will go through it and remove things
    while (!minHeap.empty()) {
      int smallestValue = minHeap.top();

      for (int i = 0; i < groupSize; i++) {
        int current = smallestValue + i;
        if (count[current] == 0) {
          // not found, return false
          return false;
        }

        count[current]--;
        if (count[current] == 0) {
          // no more, if not the smallest, return False
          if (current != minHeap.top()) {
            return false;
          }
          minHeap.pop();
        }
      }
    }
    return true;
  }
};
