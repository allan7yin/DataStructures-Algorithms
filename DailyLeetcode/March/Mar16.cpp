#include <unordered_map>
#include <vector>
using namespace std;
/* How to solve this:
    - We make a hashmap: hashing the difference in ones and zeroes to an index
    - keep the minimum of this
    - at each point in the index, we calculate the longest length so far
    - keep doing this until we reach the end


    Consider: 1 1 1 0 0
*/
class Solution {
public:
  int findMaxLength(vector<int> &nums) {
    int maxLength = 0;
    int ones = 0;
    int zeroes = 0;
    unordered_map<int, int> indexMap;

    for (int i = 0; i < nums.size(); i++) {
      if (nums[i] == 1) {
        ones++;
      } else {
        zeroes++;
      }

      // if count != 0, add this as a prefix
      if (indexMap.find(ones - zeroes) == indexMap.end()) {
        indexMap[ones - zeroes] = i;
      }
      // calculate maxLength if prefix of count has been encountered before
      if (ones == zeroes) {
        maxLength = ones + zeroes;
      } else if (indexMap.find(ones - zeroes) != indexMap.end()) {
        int idx = indexMap[ones - zeroes];
        maxLength = max(maxLength, i - idx);
      }
    }
    return maxLength;
  }
};