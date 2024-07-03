#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int minSteps(string s, string t) {
        int result = 0;
        vector<int> map1(26,0);
        vector<int> map2(26,0);

        for (int i = 0; i < s.size(); i++) {
            map1[s[i]-'a']++;
            map2[t[i]-'a']++;
        }

        // now loop through both 
        for (char i = 'a'; i <= 'z'; i++) {
            if (map1[i-'a'] == 0) {
                continue;
            } else if (map2[i-'a'] == 0) {
                result += map1[i-'a'];
            } else if (map1[i-'a'] > map2[i-'a']) {
                result += (map1[i-'a'] - map2[i-'a']);
            }
        }

        return result;
    }
};

int main() {}