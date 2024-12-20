#include <string>
#include <vector>
using namespace std;

class Solution {
  public:
    int lengthOfLastWord(string s) {
        int buffer = 0;
        bool hadSpace = false;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == ' ') {
                hadSpace = true;
            } else {
                if (hadSpace) {
                    buffer = 0;
                    hadSpace = !hadSpace;
                }
                buffer++;
            }
        }
        return buffer;
    }
};