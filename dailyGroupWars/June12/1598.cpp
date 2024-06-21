#include <string>
#include <vector>
using namespace std;

class Solution {
public:
  int minOperations(vector<string> &logs) {
    int position = 0;
    for (string &log : logs) {
      if (log[0] != '.') {
        position++;
      } else if (log.size() == 3 && position > 0) {
        position--;
      }
    }
    return position;
  }
};