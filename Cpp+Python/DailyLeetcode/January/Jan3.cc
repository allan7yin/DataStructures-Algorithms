#include <vector>
#include <string>

using namespace std;

/*
Jan 3rd, 2024
    - Laser Beams: https://leetcode.com/problems/number-of-laser-beams-in-a-bank/?envType=daily-question&envId=2024-01-03
*/
class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        vector<int> lasers;
        int num_lasers = 0;
        for (int i = 0; i < bank.size(); i++) {
            int count = num_ones(bank[i]);
            if (count > 0) {
                lasers.push_back(count);
            }
        }

        for (int i = 0; i + 1 < lasers.size(); i++) {
            num_lasers += lasers[i]*lasers[i+1];
        }
        return num_lasers;
    }

    int num_ones(string row) {
        int count = 0;
        for (char ch: row) {
            if (ch == '1') {
                count++;
            }
        }
        return count;
    }
};

int main() {
    Solution sol;
    vector<string> bank = {"011001","000000","010100","001000"};
    vector<string> bank2 = {"000","111","000"};
    sol.numberOfBeams(bank2);
}