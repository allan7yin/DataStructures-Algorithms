#include "../bits/stdc++.h"
using namespace std;

class Solution {
  public:
    long long distributeCandies(int n, int limit) {
        long long count = 0;

        for (int i = 0; i <= min(n, limit); i++) {
            int remaining = n - i;
            // what can child 2 take?
            int minTake = max(0, remaining - limit);
            int maxTake = min(limit, remaining);

            // add this range of values
            if (maxTake >= minTake) {
                count += (maxTake - minTake + 1);
            }
        }

        return count;
    }
};