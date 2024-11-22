#include <vector>
using namespace std;

class Solution {
  public:
    vector<int> findArray(vector<int> &pref) {
        vector<int> sol(pref.size(), 0);
        int x = 0;
        for (int i = 0; i < pref.size(); i++) {
            sol[i] = x ^ pref[i];
            x = pref[i];
        }
        return sol;
    }
};