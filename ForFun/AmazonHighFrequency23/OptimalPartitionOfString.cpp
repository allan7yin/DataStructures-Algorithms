#include <string>
#include <vector>

using namespace std;

class Solution {
public:
  int partitionString(string s) {
    int partitions = 1;
    vector<int> count(26, 0);
    for (int i = 0; i < s.size(); i++) {
      if (count[s[i] - 'a'] > 0) {
        partitions++;
        // reset the count vector
        for (int &num : count) {
          num = 0;
        }
      }
      count[s[i] - 'a']++;
    }
    return partitions;
  }
};
