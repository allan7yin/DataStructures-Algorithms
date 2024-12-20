#include <string>

using namespace std;

class Solution {
  public:
    bool isPalindrome(string s) {
        string temp = "";
        for (auto &ch : s) {
            if (isalnum(ch)) {
                temp += tolower(ch);
            }
        }
        int l = 0, r = temp.size() - 1;
        while (l <= r) {
            if (temp[l] != temp[r]) return false;
            l++;
            r--;
        }
        return true;
    }
};