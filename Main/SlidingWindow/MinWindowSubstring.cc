#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        // need to use hashmap now, we can have uppercase and lowercase
        int l = 0, r = 0, minL = INT_MAX, minLength = INT_MAX;
        unordered_map<char, int> fmap;

        for (char &ch: t) {
            fmap[ch]++;
        }

        int counter = t.size(); // the number of remaining things needed to be matched, want this 0
        
        // positive entry means current window does not have t -> move r
        while (r < s.size()) {
            if (fmap[s[r]] > 0) {
                counter--;
            }

            fmap[s[r]]--;
            r++;

            while (counter == 0) {
                // means we can move l and shrink the window as much as possible
                if ((r - l) < minLength) {
                    minL = l;
                    minLength = r-l;
                }

                // remove l pointer's character 
                fmap[s[l]]++;
                if (fmap[s[l]] > 0) {
                    counter++;
                }
                l++;
            }
        }
        if (minLength != INT_MAX) {
            return s.substr(minL, minLength);
        } else {
            return "";
        }
    }
};

int main() {
    Solution sol;
    string s1 = "ADOBECODEBANC";
    string s2 = "ABC";
    sol.minWindow(s1,s2);
}