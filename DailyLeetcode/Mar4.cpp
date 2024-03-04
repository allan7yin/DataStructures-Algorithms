#include <vector>
using namespace std;

class Solution {
public:
  int bagOfTokensScore(vector<int> &tokens, int power) {
    // greedy algorithm with 2 pointers
    // if we need to take power, we do so from right
    // if we can get points for power, do so from the left
    sort(tokens.begin(), tokens.end());
    int score = 0;
    int maxScore = 0;
    int l = 0, r = tokens.size() - 1;
    while (l <= r) {
      if (power >= tokens[l]) {
        score++;
        power -= tokens[l];
        maxScore = max(maxScore, score);
        l++;
      } else if (score >= 1) {
        score--;
        power += tokens[r];
        r--;
      } else {
        break;
      }
    }
    return maxScore;
  }
};
