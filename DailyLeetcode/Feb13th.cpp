#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    string firstPalindrome(vector<string>& words) {
        for (string &word:words) {
            if (isPalindrome(word)) {
                return word;
            }
        }
        return "";
    }
    bool isPalindrome(string word) {
        int l = 0, r = word.size() - 1;
        while (l < r) {
            if (word[l] != word[r]) {
                return false;
            }
            l++;
            r--;
        }
        return true;
    }
};
