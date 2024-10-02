#include <queue>
#include <vector>

using namespace std;

class Solution {
public:
  vector<int> kthSmallestPrimeFraction(vector<int> &arr, int k) {
    priority_queue<double, vector<double>, greater<double>> fractions;
    int minFrac = 1;
    // push all possible fractions into the pq
    for (int r = arr.size() - 1; r >= 0; r--) {
      int l = 0;
      // do a binary search for a smaller fraction?
      while (l < r) {
        fractions.push()
      }
    }
  }
};
