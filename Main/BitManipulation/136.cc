#include <vector>
using namespace std;
/*
This is fundamental idea in bit-manipulation questions -> 0 XOR n = n
- so in this question, if some number XOR itself, becomes 0 again, so we just take XOR of all the elements
  and it will return to us the unique element
*/
class Solution {
  public:
    int singleNumber(vector<int> &nums) {
        int bm = 0;
        for (int &num : nums) {
            bm = bm ^ num;
        }
        return bm;
    }
};