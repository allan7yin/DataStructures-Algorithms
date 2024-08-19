#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
    unordered_map<char, vector<char>> mp = {
        {'2', {'a', 'b', 'c'}},
        {'3', {'d', 'e', 'f'}},
        {'4', {'g', 'h', 'i'}},
        {'5', {'j', 'k', 'l'}},
        {'6', {'m', 'n', 'o'}},
        {'7', {'p', 'q', 'r', 's'}},
        {'8', {'t', 'u', 'v'}},
        {'9', {'w', 'x', 'y', 'z'}}};

    vector<string> result;

  public:
    vector<string> letterCombinations(string digits) {
        if (digits.size() == 0) return {};
        string sum = "";
        f(digits, sum, 0);
        return result;
    }

    void f(string digits, string sum, int i) {
        if (i >= digits.size()) {
            result.push_back(sum);
            return;
        }

        // move through all possibilities
        for (auto &ch : mp[digits[i]]) {
            sum += ch;
            f(digits, sum, i + 1);
            sum.pop_back();
        }
    }
};