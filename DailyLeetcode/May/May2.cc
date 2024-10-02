#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    int findMaxK(vector<int>& nums) {
      unordered_set<int> seen;
      int max_num = -1;
      for (int &num:nums) {
        if (seen.find(-1 * num) != seen.end()) {
          // means the negative is in the array 
          max_num = max(max_num, abs(num));
        }
        seen.insert(num);
      }
      return max_num;
    }
};
