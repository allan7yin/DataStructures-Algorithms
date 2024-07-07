#include <string>
#include <cmath>
#include <algorithm>

using namespace std;

class Solution {
public:
    string decodeString(string s) {
        string st = "";
        for (int i = 0; i < s.size(); i++) {
            if (s[i] != ']') {
                st.push_back(s[i]);
                continue;
            }
            // we have the corresponding index for [ also, so, 
            string temp = "";
            while (st.back() != '[') {
                temp += st.back();
                st.pop_back();
            }
            st.pop_back();
            reverse(temp.begin(), temp.end());
            int num = 0;
            int count = 0;
            while (!st.empty() && isdigit(st.back())) {
                num += pow(10, count)*(st.back() - '0');
                count++;
                st.pop_back();
            }
            for (int i = 0; i < num; i++) {
                st += temp;
            }
        }
        return st;
    }
};

int main() {}