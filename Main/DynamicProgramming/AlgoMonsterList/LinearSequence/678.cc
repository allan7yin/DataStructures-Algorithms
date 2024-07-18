#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
  public:
    bool checkValidString(string s) {
        unordered_map<char, char> m = {
            {'(', ')'}};

        vector<char> st;
        for (char &ch : s) {
            if (!st.empty() && (m[st.back()] == ch || ch == '*')) {
                st.pop_back();
            }
        }
        return st.empty();
    }
};