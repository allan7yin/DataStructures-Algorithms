#include <stack>
#include <vector>
using namespace std;

class Solution {
  public:
    vector<int> dailyTemperatures(vector<int> &temperatures) {
        int n = temperatures.size();
        vector<int> result(n, 0);
        stack<int> st;
        for (int i = 0; i < n; i++) {
            while (!st.empty() && temperatures[i] > temperatures[st.top()]) {
                int idx = st.top();
                result[idx] = i - idx;
                st.pop();
            }
            st.push(i);
        }
        return result;
    }
};