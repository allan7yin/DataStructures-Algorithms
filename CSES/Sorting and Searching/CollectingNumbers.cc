#include <iostream>
#include <vector>

using namespace std;

int numRounds(vector<int> &nums) {
    int n = nums.size();
    vector<bool> free(n, true);
    int rounds = 0;
    int count = 0;

    while (count < n) {
        bool firstFound = false;
        int prev = nums[0];

        for (int i = 0; i < n; i++) {
            if (!firstFound && free[i]) {
                prev = nums[i];
                firstFound = true;
                count++;
                free[i] = false;
            } else if (free[i] && prev < nums[i]) {
                // at this point, already found the first one
                count++;
                free[i] = false;
                prev = nums[i];
            } else {
                continue;
            }
        }
        rounds++;
    }

    return rounds;
}

int main() {
    int n;
    cin >> n;

    vector<int> nums(n);

    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    cout << numRounds(nums) << endl;
}