#include <vector>
using namespace std;

class Solution {
public:
  static bool compare(vector<int> &a, vector<int> &b) {
    return (a[0] != b[0]) ? a[0] < b[0] : a[1] > b[1];
  }
  int numberOfWeakCharacters(vector<vector<int>> &properties) {
    int n = properties.size();
    int count = 0;
    sort(properties.begin(), properties.end(), compare);
    // iterate
    int maxY = 0;
    for (int i = n - 1; i >= 0; i--) {
      if (properties[i][1] < maxY) {
        count++;
      }
      maxY = max(maxY, properties[i][1]);
    }
    return count;
  }
};
/*
1,5
1,5
1,2
3,10
4,3
7,7
7,3
8,10
9,8
9,7
*/
