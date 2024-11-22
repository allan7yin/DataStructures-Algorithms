#include <vector>
using namespace std;

class Solution {
  public:
    int minEatingSpeed(vector<int> &piles, int h) {
        long long maxVal = 0;
        for (int i = 0; i < piles.size(); i++) {
            maxVal = max(maxVal, (long long)piles[i]);
        }

        // binary search this
        long long minEat = maxVal;
        long long l = 1, r = maxVal;
        while (l <= r) {
            long long m = l + (r - l) / 2;
            long long temp = 0;
            for (int &p : piles) {
                temp += (p / m);
                if (p % m != 0) temp++;
            }
            if (temp <= h) {
                minEat = m;
                r = m - 1;
            } else {
                l = m + 1;
            }
        }
        return minEat;
    }
};