#include <vector>
using namespace std;

/*
Jan 1st, 2024
    - Assign Cookies: https://leetcode.com/problems/assign-cookies/description/?envType=daily-question&envId=2024-01-01
*/

class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int count = 0;
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());

        int l1 = 0, l2 = 0;
        while (l1 < g.size() && l2 < s.size()) {
            if (g[l1] <= s[l2]) {
                l1++;
                count++;
            }
            l2++;
        }
        return count;
    }
};