#include <string>
#include <stack>
#include <unordered_map>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        unordered_map<char, char> map = {
            {')', '('},
            {']', '['},
            {'}', '{'}
            };
        
        stack<char> st;
        for (int i = 0; i < s.size(); i++) {
            if (map.find(s[i]) == map.end()) {
                // means this character is one of ( { [ 
                st.push(s[i]);
            } else {
                // means we have one of ) } ] -> check if top of the stack is corresponding one, if so, pop
                if (!st.empty() && st.top() == map[s[i]]) {
                    st.pop();
                } else {
                    st.push(s[i]);
                }
            }
        }

        return st.empty();

    }
};