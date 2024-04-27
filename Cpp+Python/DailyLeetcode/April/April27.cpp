#include <climits>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

/*
- We can solve this by doing a DO tabulation
- The bottom shows the naive recursive approach, the top one is the optimized
method
*/
class Solution {
public:
  int findRotateSteps(string ring, string key) {
    vector<vector<int>> dp(ring.size(), vector<int>(key.size(), INT_MAX));
  }
};
