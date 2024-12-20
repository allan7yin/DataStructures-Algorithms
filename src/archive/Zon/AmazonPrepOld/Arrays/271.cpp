#include <string>
#include <vector>
using namespace std;

/*
 * Runtime of this:
 * - Encode is just looping through each string -> O(n)
 * - Decode is same, O(n)
 */
class Codec {
public:
  // Encodes a list of strings to a single string.
  string encode(vector<string> &strs) {
    string result = "";
    for (auto &str : strs) {
      int size = str.size();
      result += to_string(size);
      result += "#";
      result += str;
    }
    // cout << result << endl;
    return result;
  }

  // Decodes a single string to a list of strings.
  vector<string> decode(string s) {
    string buffer = "";
    vector<string> result;
    for (int i = 0; i < s.size(); i++) {
      if (s[i] <= '9' && s[i] >= '0') {
        buffer += s[i];
      } else if (s[i] == '#') {
        int len = stoi(buffer);
        buffer = "";
        string temp = s.substr(i + 1, len);
        i += len;
        result.push_back(temp);
      }
    }
    return result;
  }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.decode(codec.encode(strs));
