#include <vector>
using namespace std;

class Solution {
public:
  int maxSatisfied(vector<int> &customers, vector<int> &grumpy, int minutes) {
    int sum = 0;
    int maxCustomersSatisfied = 0;
    int baselineSatisfied = 0;
    for (int i = 0; i < customers.size(); i++) {
      baselineSatisfied += ((1 - grumpy[i]) * customers[i]);
      if (i < minutes)
        sum += ((1 - grumpy[i]) * customers[i]);
    }

    // now, we start by making first k  = 1, and move the window right
    baselineSatisfied -= sum;
    int l = 0;
    for (int r = 0; r < customers.size(); r++) {
      if (r < minutes) {
        baselineSatisfied += customers[r];
        maxCustomersSatisfied = max(maxCustomersSatisfied, baselineSatisfied);
        continue;
      } else {
        baselineSatisfied -= ((1 - grumpy[r]) * customers[r]);
        baselineSatisfied += customers[r];

        baselineSatisfied -= customers[l];
        baselineSatisfied += ((1 - grumpy[l]) * customers[l]);
        maxCustomersSatisfied = max(maxCustomersSatisfied, baselineSatisfied);
        l++;
      }
    }
    return maxCustomersSatisfied;
  }
};