#include <vector>
using namespace std;

class Solution {
public:
  int kthFactor(int n, int k) {
    vector<int> factors;
    int s = 1;
    while (s <= n) {
      if (n % s == 0) {
        factors.push_back(s);
      }
      s++;
    }

    return factors.size() >= k ? factors[k - 1] : -1;
  }
};
