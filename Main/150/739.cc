#include <stack>
#include <vector>

using namespace std;
// this reviews the idea of monotonically increasing or decreasing stacks
class Solution {
public:
  vector<int> dailyTemperatures(vector<int> &temperatures) {
    int n = temperatures.size();
    vector<int> result(n, 0);
    stack<int> st;
    for (int i = n - 1; i >= 0; i--) {
      while (!st.empty() && temperatures[i] >= temperatures[st.top()]) {
        st.pop();
      }

      result[i] = (st.empty()) ? 0 : st.top() - i;
      st.push(i);
    }
    return result;
  }
};
