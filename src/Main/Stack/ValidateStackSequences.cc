#include <vector>

using namespace std;

class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        int n = pushed.size();
        vector<int> st;
        int j = 0;
        for (int i = 0; i < n; i++) {
            st.push_back(pushed[i]);
            while (!st.empty() && st.back() == popped[j]) {
                j++;
                st.pop_back();
            }
        }
        return st.size() == 0;
    }
};

int main() {}