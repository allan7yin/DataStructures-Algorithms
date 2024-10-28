#include <iostream>
#include <vector>

using namespace std;

int numRounds(vector<int> &nums) {
    int n = nums.size();
    int rounds = 1;
    vector<int> indices(n + 1, 0);

    for (int i = 0; i < n; i++) {
        indices[nums[i]] = i;
    }

    for (int i = 1; i < n; i++) {
        if (indices[i] > indices[i + 1]) {
            rounds++;
        }
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