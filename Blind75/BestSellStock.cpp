#include <vector>
using namespace std;

class Solution {
public:
  int maxProfit(vector<int> &prices) {
    int maxEarns = 0;
    int l = 0;
    int prev = 0;

    for (int r = 0; r < prices.size(); r++) {
      if (prices[r] < prices[l]) {
        l = r;
      } else {
        maxEarns = max(maxEarns, (prices[r] - prices[l]));
      }
    }
    return maxEarns;
  }
};
