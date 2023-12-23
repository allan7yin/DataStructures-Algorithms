#include <vector>
#include <iostream>
#include <string>
#include <map>

using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) return false;
        unordered_map<char,int> map1;
        unordered_map<char,int> map2;

        for (int i = 0; i < s.size(); i++) {
            map1[s[i]] ++;
            map2[t[i]] ++;
        }

        return map1 == map2;      
    }
};

int main()
{
    Solution solution;
    string s1 = "allan";
    string s2 = "abban";
    string s3 = "aanll";
    cout << "Test one is " << solution.isAnagram(s1, s2) << endl;
    cout << "Test two is " << solution.isAnagram(s1, s3) << endl;


}