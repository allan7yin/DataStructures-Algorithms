#include <vector>

using namespace std;

class Solution {
public:
  vector<int> maximumBeauty(vector<vector<int>> &items, vector<int> &queries) {
    sort(items.begin(), items.end());
    // each index, store the max beauty up until that index
    int temp = items[0][1];
    for (auto &item : items) {
      if (item[1] > temp) {
        temp = item[1];
      }
      item[1] = temp;
    }

    vector<int> result;

    for (int &query : queries) {

      int l = 0, r = items.size() - 1;
      int maxBeauty = 0;

      while (l <= r) {
        int m = l + (r - l) / 2;
        if (items[m][0] <= query) {
          maxBeauty = max(maxBeauty, items[m][1]);
          l = m + 1;
        } else {
          r = m - 1;
        }
      }

      result.push_back(maxBeauty);
    }

    return result;
  }
};
