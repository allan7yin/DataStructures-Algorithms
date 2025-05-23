#include "../bits/stdc++.h"

using namespace std;

class Codec {
  public:
    // Encodes a list of strings to a single string.
    string encode(vector<string> &strs) {
        string encoded = "";
        for (string &str : strs) {
            int n = str.size();
            encoded += to_string(n);
            encoded += '#';
            encoded += str;
        }

        return encoded;
    }

    // Decodes a single string to a list of strings.
    vector<string> decode(string s) {
        vector<string> words;
        string length;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] <= '9' && s[i] >= '0') {
                length += s[i];
            } else if (s[i] == '#') {
                // delimiter, the rest of the word is a word
                string word = s.substr(i + 1, stoi(length));
                i += stoi(length);
                length = "";
                words.push_back(word);
            }
        }
        return words;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.decode(codec.encode(strs));#include "../bits/stdc++.h"

using namespace std;

class Codec {
  public:
    // Encodes a list of strings to a single string.
    string encode(vector<string> &strs) {
        string encoded = "";
        for (string &str : strs) {
            int n = str.size();
            encoded += to_string(n);
            encoded += '#';
            encoded += str;
        }

        return encoded;
    }

    // Decodes a single string to a list of strings.
    vector<string> decode(string s) {
        vector<string> words;
        string length;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] <= '9' && s[i] >= '0') {
                length += s[i];
            } else if (s[i] == '#') {
                // delimiter, the rest of the word is a word
                string word = s.substr(i + 1, stoi(length));
                i += stoi(length);
                length = "";
                words.push_back(word);
            }
        }
        return words;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.decode(codec.encode(strs));#include "../bits/stdc++.h"

using namespace std;

class Codec {
  public:
    // Encodes a list of strings to a single string.
    string encode(vector<string> &strs) {
        string encoded = "";
        for (string &str : strs) {
            int n = str.size();
            encoded += to_string(n);
            encoded += '#';
            encoded += str;
        }

        return encoded;
    }

    // Decodes a single string to a list of strings.
    vector<string> decode(string s) {
        vector<string> words;
        string length;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] <= '9' && s[i] >= '0') {
                length += s[i];
            } else if (s[i] == '#') {
                // delimiter, the rest of the word is a word
                string word = s.substr(i + 1, stoi(length));
                i += stoi(length);
                length = "";
                words.push_back(word);
            }
        }
        return words;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.decode(codec.encode(strs));