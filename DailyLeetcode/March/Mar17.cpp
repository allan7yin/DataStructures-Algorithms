#include <vector>
using namespace std;

// solve with stack
class Solution {
public:
  vector<vector<int>> insert(vector<vector<int>> &intervals, vector<int> &newInterval) {
    vector<vector<int>> result;
    result.push_back(newInterval);
    for (auto &interval : intervals) {
      vector<int> top = result.back();
      if (isOverlap(top, interval)) {
        // first check if there is overlap, if there is, pop, merge and re-push
        result.pop_back();
        top = {min(top[0], interval[0]), max(top[1], interval[1])};
        result.push_back(top);
      } else {
        // no overlap, push the smaller vector
        if (interval[0] <= top[0] && interval[1] <= top[1]) {
          result.pop_back();
          result.push_back(interval);
          result.push_back(top);
        } else {
          result.push_back(interval);
        }
      }
    }
    return result;
  }

  bool isOverlap(vector<int> first, vector<int> second) {
    if (second[0] >= first[0] && second[0] <= first[1]) {
      return true;
    }

    return first[0] >= second[0] && first[0] <= second[1];
  }
};