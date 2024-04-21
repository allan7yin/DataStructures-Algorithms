#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    int calPoints(vector<string>& operations) {
        int result = 0;
        vector<int> st;
        int n = operations.size();
        for (int i = 0; i < operations.size(); i++) {
            if (operations[i] == "+") {
                st.push_back(st.back() + st[st.size()-2]);
            } else if (operations[i] == "D") {
                st.push_back(st.back() * 2);
            } else if (operations[i] == "C") {
                st.pop_back();
            } else {
                st.push_back(stoi(operations[i]));
            }
        }

        for (auto &num:st) {
            result += num;
        }
        return result;
    }
};

int main () {}