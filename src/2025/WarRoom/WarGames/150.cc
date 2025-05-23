#include "../bits/stdc++.h"
using namespace std;

class Solution {
  public:
    int evalRPN(vector<string> &tokens) {
        vector<string> st;
        int result = 0;

        for (int i = 0; i < tokens.size(); i++) {
            if (tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "*" || tokens[i] == "/") {
                // pop off 2
                int num1 = stoi(st.back());
                st.pop_back();
                int num2 = stoi(st.back());
                st.pop_back();
                st.push_back(1);
            }
        }

        return 0;
    }
};