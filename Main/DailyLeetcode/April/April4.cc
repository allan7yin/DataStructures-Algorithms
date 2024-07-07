#include <string>
using namespace std;

// suspect this is a stack problem
class Solution {
public:
  int maxDepth(string s) {
    int n = s.size();
    int maxFoundDepth = 0;
    int currentDepth = 0;

    for (int i = 0; i < n; i++) {
      if (s[i] == '(') {
        currentDepth++;
      } else if (s[i] == ')') {
        maxFoundDepth = max(maxFoundDepth, currentDepth);
        currentDepth--;
      }
    }
    return maxFoundDepth;
  }
};