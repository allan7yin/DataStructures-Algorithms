#include <string>
#include <vector>

using namespace std;

class Solution {
public:
  int maxScore(string s) {
    int score = 0;
    int n = s.size();
    vector<int> ones(n, 0);
    int counter = 0;

    for (int i = s.size() - 1; i >= 0; i--) {
      if (s[i] == '1') {
        counter++;
      }
      ones[i] = counter;
    }

    counter = 0;
    for (int i = 0; i < s.size() - 1; i++) {
      if (s[i] == '0') {
        counter++;
      }
      score = max(score, ones[i + 1] + counter);
    }
    return score;
  }
};