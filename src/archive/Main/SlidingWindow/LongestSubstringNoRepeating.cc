#include <string>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l = 0, r = 0, max_num = 0;
        unordered_set<char> mySet;
        while (r < s.size()) {
            while (mySet.find(s[r]) != mySet.end()) {
                mySet.erase(s[l]);
                l++;
            }
            mySet.insert(s[r]);
            max_num = max(max_num, r - l + 1);
            r++;
        }
        return max_num;
    }
};

int main() {}