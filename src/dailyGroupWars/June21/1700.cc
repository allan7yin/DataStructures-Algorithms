#include <queue>
#include <vector>

class Solution {
public:
  int countStudents(std::vector<int> &students, std::vector<int> &sandwiches) {
    int result = students.size();
    std::deque<int> s(students.begin(), students.end());
    for (int i = 0; i < sandwiches.size(); i++) {
      int numStudents = s.size();
      while (!s.empty()) {
        if (numStudents == 0) {
          return result;
        }
        if (sandwiches[i] == s.front()) {
          s.pop_front();
          result--;
          break;
        } else {
          int top = s.front();
          s.pop_front();
          s.push_back(top);
        }
        numStudents--;
      }
    }
    return result;
  }
};