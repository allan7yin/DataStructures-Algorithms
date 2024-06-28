#include <unordered_map>
#include <vector>

using namespace std;

// It seems some dp problems like this are easier to think about recursively
// Nice, beats 90% of submissions : D
class Solution {
public:
  long long mostPoints(vector<vector<int>> &questions) {
    int n = questions.size();
    vector<long long> mem(n, -1);
    return recurse(0, mem, questions);
  }

  long long recurse(int i, vector<long long> &mem, vector<vector<int>> &questions) {
    if (i >= questions.size())
      return 0;
    if (mem[i] != -1)
      return mem[i];

    // we do the current question
    mem[i] = questions[i][0] + recurse(i + questions[i][1] + 1, mem, questions);
    // we don't do the current question
    mem[i] = max(mem[i], recurse(i + 1, mem, questions));
    return mem[i];
  }
};