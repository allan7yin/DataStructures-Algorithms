#include <vector>

using namespace std;

class Solution {
  public:
    int numPairsDivisibleBy60(vector<int> &time) {
        vector<int> mod(60, 0);
        for (int &t : time) {
            mod[t % 60]++;
        }

        long long n = mod[0];
        long long result = (n * (n - 1)) / 2;
        int l = 1, r = 59;
        while (l < r) {
            result += (mod[l] * mod[r]);
            l++;
            r--;
        }
        n = mod[30];
        result += (n * (n - 1)) / 2;
        return result;
    }
};