#include <queue>
#include <string>
#include <unordered_set>
#include <utility>
#include <vector>

using namespace std;

class Solution {
public:
  int openLock(vector<string> &deadends, string target) {
    queue<pair<string, int>> q;
    unordered_set<string> invalid(deadends.begin(), deadends.end());
    if (invalid.find("0000") == invalid.end()) {
      q.push(make_pair("0000", 0));
      invalid.insert("0000");
    }

    while (!q.empty()) {
      // take the top element, and change each digit by, add to queue if valid
      string top_string = q.front().first;
      int top_turns = q.front().second;
      q.pop();

      if (top_string == target) {
        return top_turns;
      }

      for (int i = 0; i < 4; i++) {
        char temp = top_string[i];
        // now rotate right and left and see
        if (top_string[i] == '9') {
          top_string[i] = '0';
        } else {
          top_string[i] += 1;
        }
        if (invalid.find(top_string) == invalid.end()) {
          q.push(make_pair(top_string, top_turns + 1));
          invalid.insert(top_string);
        }

        // now reset and do the other way
        top_string[i] = temp;
        if (top_string[i] == '0') {
          top_string[i] = '9';
        } else {
          top_string[i] -= 1;
        }
        if (invalid.find(top_string) == invalid.end()) {
          q.push(make_pair(top_string, top_turns + 1));
          invalid.insert(top_string);
        }
        top_string[i] = temp;
      }
    }

    return -1;
  }
};
