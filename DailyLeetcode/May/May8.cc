include<algorithm>
#include <string>
#include <unordered_map>
#include <vector>
    using namespace std;

class Solution {
public:
  vector<string> findRelativeRanks(vector<int> &score) {
    vector<int> copy = score;
    sort(copy.begin(), copy.end(), std::greater<int>());
    unordered_map<int, string> map;

    for (int i = 0; i < copy.size(); i++) {
      if (i == 0) {
        map[copy[i]] = "Gold Medal";
      } else if (i == 1) {
        map[copy[i]] = "Silver Medal";
      } else if (i == 2) {
        map[copy[i]] = "Bronze Medal";
      } else {
        map[copy[i]] = std::to_string(i + 1);
      }
    }

    // now, return each of these
    vector<string> result;
    for (int i = 0; i < score.size(); i++) {
      result.push_back(map[score[i]]);
    }
    return result;
  }
};

// [10,3,8,9,4]
// sorted version: [10,9,8,4,3]
// make a hashmap from this
