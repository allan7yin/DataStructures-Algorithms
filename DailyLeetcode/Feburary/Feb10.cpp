#include <vector>
#include <string>
/*
Link: https://leetcode.com/problems/palindromic-substrings/description/?envType=daily-question&envId=2024-02-10
*/

using namespace std;
class Solution {
public:
    int countSubstrings(string s) {
        // for each index, we'll move both ways checking if it is palindrome. We can also cash this 
        int n = s.size();
        int count = 0;
        for (int i = 0; i < n; i++) {
            vector<pair<int, int>> start = {make_pair(i,i+1), make_pair(i,i)};
            for (auto &kv:start) {
                int l = kv.first, r = kv.second;
                while (l >= 0 && r < n && s[l] == s[r]) {
                    count++;
                    l--;
                    r++;
                }
            }
        }
        return count;
    }
};