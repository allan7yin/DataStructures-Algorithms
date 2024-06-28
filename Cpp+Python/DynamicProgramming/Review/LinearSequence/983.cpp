#include <unordered_map>
#include <vector>
using namespace std;

// let's first do a recursive solution

class Solution {
public:
  int mincostTickets(vector<int> &days, vector<int> &costs) {
    // now, let's look for an iterative method, but the recursive methods ideas are the same
    vector<int> lengths = {1, 7, 30};
    unordered_map<int, int> mem;
    int n = days.size();
    for (int i = n - 1; i >= 0; i--) {
      mem[i] = INT_MAX;
      for (int p = 0; p < 3; p++) {
        int j = i;
        while (j < n && days[j] < days[i] + lengths[p]) {
          j++;
        }

        mem[i] = min(mem[i], mem[j] + costs[p]);
      }
    }
    return mem[0];
  }

  int mincostTicketsRecurse(vector<int> &days, vector<int> &costs) {
    vector<int> lengths = {1, 7, 30};
    unordered_map<int, int> memoize;
    return recurse(0, memoize, days, lengths, costs);
  }

  int recurse(int index, unordered_map<int, int> &memoize, vector<int> &days, vector<int> &lengths, vector<int> &costs) {
    if (memoize.find(index) != memoize.end()) {
      return memoize[index];
    }

    if (index == days.size())
      return 0;
    memoize[index] = INT_MAX;
    for (int i = 0; i < 3; i++) {
      int j = index;
      while (j < days.size() && days[j] < days[index] + lengths[i]) {
        j++;
      }

      // index j is the day where our previous pass is no longer valid
      memoize[index] = min(memoize[index], recurse(j, memoize, days, lengths, costs) + costs[i]);
    }
    return memoize[index];
  }
};