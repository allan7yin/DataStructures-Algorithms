#include <vector>
using namespace std;

class Solution {
public:
  int numRescueBoats(vector<int> &people, int limit) {
    int numBoats = 0;
    sort(people.begin(), people.end());
    // want to pair heaviest with lightest when possible

    int l = 0, r = people.size() - 1;
    while (l < r) {
      if (people[l] + people[r] <= limit) {
        numBoats++;
        l++;
        r--;
      } else {
        numBoats++;
        r--;
      }
      if (l == r) {
        numBoats++;
      }
    }
    return numBoats;
  }
};
