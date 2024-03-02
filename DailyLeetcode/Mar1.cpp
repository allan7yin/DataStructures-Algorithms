#include <string>
using namespace std;

class Solution {
public:
  string maximumOddBinaryNumber(string s) {
    // count how many 1's are in s
    int ones = 0;
    for (auto &ch : s) {
      if (ch == '1') {
        ones++;
      }
    }
    int zeroes = s.size() - ones;
    string result = "";
    for (int i = 0; i < ones - 1; i++) {
      result += "1";
    }
    for (int i = 0; i < zeroes; i++) {
      result += "0";
    }
    result += "1";
    return result;
  }
};
