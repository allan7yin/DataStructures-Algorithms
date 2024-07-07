#include <string>

using namespace std;
/*
    - Another instance of monotonic stack 
*/
class Solution {
public:
    string removeKdigits(string num, int k) {
        if (num.size() == 1 && k > 0) {return "0";}
        string stack;
        int i = 0;
        while (i < num.size()) {
            while (!stack.empty() && stack.back() > num[i] && k > 0) {
                stack.pop_back();
                k--;
            } 
            if (!stack.empty() && stack.back() == '0' && stack.size() == 1) {
                stack.pop_back();
            }
            stack.push_back(num[i]);
            i++;
        }

        while (k > 0 && !stack.empty()) {
            stack.pop_back();
            k--;
        }

        return (stack.size() == 0) ? "0" : stack;
    }
};

int main() {
    Solution sol;
    string num = "1432219";
    sol.removeKdigits(num,3);
}