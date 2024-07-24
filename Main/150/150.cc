#include <functional>
#include <stack>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
  int evalRPN(vector<string> &tokens) {
    stack<int> st;
    unordered_map<string, function<int(int, int)>> operators = {
        {"+", [](int a, int b) { return a + b; }},
        {"-", [](int a, int b) { return a - b; }},
        {"*", [](int a, int b) { return a * b; }},
        {"/", [](int a, int b) { return a / b; }}};

    for (string &token : tokens) {
      if (operators.find(token) != operators.end()) {
        int b = st.top();
        st.pop();
        int a = st.top();
        st.pop();
        st.push(operators[token](a, b));
      } else {
        st.push(stoi(token));
      }
    }
    return st.top();
  }
};
