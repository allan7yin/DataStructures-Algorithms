#include <vector>
using namespace std;

/*
How to solve:
  - Sort by the first element
  - Maintain stack of disjoint sets. Pop if top and next interval intersect. Push that intersection
  - DO this, and return number of disjoint intersections
*/
class Solution {
public:
  int findMinArrowShots(vector<vector<int>> &points) {
    // sort by first element first
    sort(points.begin(), points.end(), compare);
    vector<vector<int>> disjoint;
    disjoint.push_back(points[0]);

    for (int i = 1; i < points.size(); i++) {
      vector<int> temp = disjoint.back();
      if (isIntersect(temp, points[i])) {
        temp = {max(temp[0], points[i][0]), min(temp[1], points[i][1])};
        disjoint.pop_back();
        disjoint.push_back(temp);
      } else {
        disjoint.push_back(points[i]);
      }
    }
    return disjoint.size();
  }

  bool compare(const vector<int> &first, const vector<int> &second) {
    return first[0] < second[0];
  }

  bool isIntersect(const vector<int> &first, const vector<int> &second) {
    return first[1] >= second[0];
  }
};
