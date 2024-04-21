#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n1 = s1.size();
        int n2 = s2.size();
        if (n1 > n2) {return false;}
        int numMatches = 0; // this is an idea that can improve runtime 
        vector<int> hmap(26,0);
        vector<int> constMap(26,0);

        for (char &ch:s1) {
            constMap[ch - 'a']++;
        }

        int l = 0, r = n1 - 1;
        for (int i = l; i <= r; i++) {
            hmap[s2[i] - 'a']++;
        }

        while (r < n2) {
            if (constMap == hmap) {
                return true;
            }
            hmap[s2[l] - 'a']--;    
            r++;
            if (r == n2) {break;}
            l++;
            hmap[s2[r] - 'a']++;
        }

        return false;        
    }
};

int main() {
    Solution sol;
    string s1 = "ab";
    string s2 = "eidboaoo";
    sol.checkInclusion(s1,s2);
}