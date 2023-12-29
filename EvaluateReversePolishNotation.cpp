#include <stack>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> myStack;
        for (int i = 0; i < tokens.size(); i++) {
            if (tokens[i].size() > 1 || isdigit(tokens[i][0])) {
                int num = stoi(tokens[i]);
                myStack.push(num);
                continue;
            }

            int num1 = myStack.top();
            myStack.pop();
            int num2 = myStack.top();
            myStack.pop();
        
            int result = 0;
            if (tokens[i] == "+") {
                result = num1 + num2;
            } else if (tokens[i] == "-") {
                result = num2 - num1;
            } else if (tokens[i] == "*") {
                result = num1 * num2;
            } else {
                result = num2 / num1;
            }
            myStack.push(result);
        }
        return myStack.top();
    }
};

int main() {}