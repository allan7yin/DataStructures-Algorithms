#include "bits/stdc++.h"

using namespace std;

/*
Idea: we need greedy solution for this problem. We iterate through the string s character by character
- we want to determine if we should take s[i] or not

Maintain monotoniclly increasing stack?
- we push s[i] onto the stack if s[i] > stack.top()
- What if it s[i] == stack.top()? skip
- what if s[i] < stack.pop()?
    - while there is a later occurency of stack.top(), and s[i] < stack.top(), we stack.pop()
    - after, we push s[i]?
- if s[i] already in stack (which we can keep track of with a vector or set, we skip, as that one has lower index)
- maintain frequency count of remianing characters for each character -> decrement as we go through
*/
class Solution {
  public:
    string removeDuplicateLetters(string s) {
        int n = s.size();
        stack<char> st;
        vector<bool> in(26);
        vector<int> count(26);

        for (char &ch : s) {
            count[ch - 'a']++;
        }

        for (int i = 0; i < n; i++) {
            count[s[i] - 'a']--;
            //  if already in the stack, continue
            if (in[s[i] - 'a']) continue;

            while (!st.empty() && s[i] < st.top() && count[st.top() - 'a'] > 0) {
                in[st.top() - 'a'] = false;
                st.pop();
            }

            st.push(s[i]);
            in[s[i] - 'a'] = true;
        }

        string result = "";
        while (!st.empty()) {
            result += st.top();
            st.pop();
        }

        reverse(result.begin(), result.end());
        return result;
    }
};