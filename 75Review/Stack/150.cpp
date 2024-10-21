#include <stack>
#include <string>
#include <vector>

using namespace std;

class Solution {
  public:
    int evalRPN(vector<string> &tokens) {
        stack<int> st;
        for (auto &tk : tokens) {
            if (tk == "+") {
                auto p = topTwo(st);
                st.push(p.first + p.second);
            } else if (tk == "-") {
                auto p = topTwo(st);
                st.push(p.first - p.second);
            } else if (tk == "*") {
                auto p = topTwo(st);
                st.push(p.first * p.second);
            } else if (tk == "/") {
                auto p = topTwo(st);
                st.push(p.first / p.second);
            } else {
                st.push(stoi(tk)); // Convert string to int for numbers
            }
        }
        return st.top();
    }

    pair<int, int> topTwo(stack<int> &st) {
        int n1, n2;
        n1 = st.top();
        st.pop();
        n2 = st.top();
        st.pop();
        return {n2, n1}; // Return as pair, n2 comes first to maintain order
    }
};
