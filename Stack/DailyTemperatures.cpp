#include <vector>
#include <stack>

using namespace std;
/*
    - Keep things pushed into a stack until an element is met that is greater than top of stack
    - If it is greater, keep popping from the stack until no longer the case 
    - push the indices onto the stack
*/
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> result(n, 0);
        stack<int> st;
        for (int i = 0; i < n; i++) {
            while (!st.empty() && temperatures[st.top()] < temperatures[i]) {
                int j = st.top();
                result[j] = i -j;
                st.pop();
            }
            st.push(i);
        }
        return result;
    }
};

int main() {}