#include <string>
#include <vector>
#include <utility>

using namespace std;

class Solution {
public:
    string removeDuplicates(string s, int k) {
        vector<pair<char,int>> stack;

        for (int i = 0; i < s.size(); i++) {
            if (!stack.empty() && stack.back().first == s[i]) {
                stack[stack.size()-1].second++;

                if (stack[stack.size()-1].second == k) {
                    stack.pop_back();
                }
            } else {
                stack.push_back(make_pair(s[i],1));
            }
        }

        string result = "";
        for (auto &kv_pair:stack) {
            for (int i = 0; i < kv_pair.second; i++) {
                result += kv_pair.first;
            }
            
        }
        return result;
    }
};

int main() {}