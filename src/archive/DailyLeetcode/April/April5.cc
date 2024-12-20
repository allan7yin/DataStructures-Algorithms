#include <algorithm>
#include <string>

class Solution {
public:
  std::string makeGood(std::string s) {
    std::string result = "";
    result += s[0];
    for (int i = 1; i < s.size(); i++) {
      if (!result.empty() && (abs(result.back() - s[i]) == 32)) {
        result.pop_back();
      } else {
        result.push_back(s[i]);
      }
    }
    return result;
  }
};