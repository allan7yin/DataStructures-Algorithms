#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> nums;

    for (int i = 2; i <= n; i += 2) {
        nums.push_back(i);
    }
    for (int i = 1; i <= n; i += 2) {
        nums.push_back(i);
    }

    bool found = true;
    for (int i = 0; i < n - 1; i++) {
        if (abs(nums[i] - nums[i + 1]) <= 1) {
            found = false;
            break;
        }
    }

    if (found) {
        for (int &num : nums) {
            cout << num << " ";
        }
    } else {
        cout << "NO SOLUTION" << endl;
    }
}