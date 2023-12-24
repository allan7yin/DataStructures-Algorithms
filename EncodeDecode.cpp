#include <string>
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    /*
     * @param strs: a list of strings
     * @return: encodes a list of strings to a single string.
     */
    string encode(vector<string> &strs) {
        string encoded = "";
        int n = 0;
        for (auto &str : strs) {
            n = str.size();
            encoded += to_string(n);
            encoded += "#";
            encoded += str;
        }
        cout << encoded << endl;
        return encoded;
    }

    /*
     * @param str: A string
     * @return: decodes a single string to a list of strings
     */
    vector<string> decode(string &str) {
        vector<string> decoded;
        int n = str.size();
        int i = 0;
        while (i < n) {
            string length = "";
            while ('0' <= str[i] && str[i] <= '9') {
                length += str[i];
                i++;
            }
            i++;
            // we have the number now, i is on #
            cout << typeid(length).name() << endl;
            int numLength = stoi(length);
            string temp = "";
            while (numLength > 0) {
                temp += str[i];
                i++;
                numLength --;
            }
            decoded.push_back(temp);
        }
        return decoded;
    }
};

int main() {
    Solution sol;
    vector<string> strings = {"lint","code","love","you"};
    string encoded = sol.encode(strings);
    vector<string> decoded = sol.decode(encoded);
    cout << "----Encoded: " << encoded << endl;
    for (auto &str : decoded) {
        cout << "word: " << str << endl;
    }

}