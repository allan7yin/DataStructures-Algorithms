#include <vector>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int l = 0;
        int r = numbers.size() - 1;
        vector<int> solution;
        while (l < r) {
            int sum = numbers[l] + numbers[r];
            if (sum < target) {
                l ++;
            } else if (sum > target) {
                r --;
            } else {
                solution.push_back(l+1);
                solution.push_back(r+1);
                break;
            }
        }
        return solution;
    }
};

int main() {}