#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
  int maxFrequencyElements(vector<int> &nums) {
    unordered_map<int, int> map;
    int maxFrequency = 0;

    for (int &num : nums) {
      map[num]++;
      maxFrequency = max(maxFrequency, map[num]);
    }

    int count = 0;
    for (auto &kv : map) {
      if (kv.second == maxFrequency) {
        count++;
      }
    }
    return count * maxFrequency;
  }
};
