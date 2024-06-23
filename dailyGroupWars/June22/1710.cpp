#include <queue>
#include <utility>
#include <vector>

using namespace std;
// use maxHeap of pairs, where the first element is units, and second is number

// Define a custom comparator for the priority queue
struct Compare {
  bool operator()(const std::pair<int, int> &p1,
                  const std::pair<int, int> &p2) {
    if (p1.first == p2.first) {
      return p1.second < p2.second;
    }
    return p1.first < p2.first;
  }
};

class Solution {
public:
  int maximumUnits(vector<vector<int>> &boxTypes, int truckSize) {
    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>,
                        Compare>
        maxHeap;
    for (int i = 0; i < boxTypes.size(); i++) {
      maxHeap.push({boxTypes[i][1], boxTypes[i][0]});
    }

    // now, we keep popping until no more capacity
    int totalUnits = 0;
    int capacity = truckSize;

    // Process the max heap
    while (!maxHeap.empty() && capacity > 0) {
      std::pair<int, int> top = maxHeap.top();
      maxHeap.pop();

      int boxesToTake = std::min(top.second, capacity);
      totalUnits += boxesToTake * top.first;
      capacity -= boxesToTake;
    }
    return totalUnits;
  }
};
