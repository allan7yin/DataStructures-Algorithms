#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;

class Solution {
public:
  int minEatingSpeed(vector<int> &piles, int h) {
    // binary search the k
    int mins = INT_MAX;
    int maxb = 0;
    for (int &p : piles) {
      maxb = max(maxb, p);
    }

    int l = 1;
    while (l <= maxb) {
      int m = (l + maxb) / 2;
      int hours = numSteps(m, piles);

      if (hours <= h) {
        mins = min(mins, m);
        maxb = m - 1;
      } else {
        // too slow,
        l = m + 1;
      }
    }

    return mins;
  }

  int numSteps(int k, vector<int> &piles) {
    // returns the number of hours needed to eat the piles of bannanas at rate k
    int hours = 0;
    for (int &p : piles) {
      hours += ceil(p / k);
    }
    return hours;
  }
};
