#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
  public:
    bool isValid(string s) {
        unordered_map<char, char> mp = {
            {'{', '}'},
            {'(', ')'},
            {'[', ']'}};
        vector<char> st;
        for (auto &ch : s) {
            if (!st.empty() && mp[st.back()] == ch) {
                st.pop_back();
                continue;
            }
            st.push_back(ch);
        }
        return st.size() == 0;
    }
};