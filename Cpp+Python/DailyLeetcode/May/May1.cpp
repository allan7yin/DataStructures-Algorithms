#include <string>
using namespace std;

class Solution {
public:
    string reversePrefix(string word, char ch) {
        int pos = -1;
        string result = "";
        // find the position of the first occurence of ch
        for (int i = 0; i < word.size(); i++) {
            if (word[i] == ch) {
                pos = i;
                break;
            }
        }

        if (pos == -1) {
            return word;
        }

        for (int i = pos; i >= 0; i--) {
            result += word[i];
        }

        for (int i = pos + 1; i < word.size(); i++) {
            result += word[i];
        }
        
        return result;
    }
};
