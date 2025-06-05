#include <iostream>
#include <vector>

using namespace std;

long bs(vector<long> &nums, long target) {
    int l = 0, r = nums.size() - 1;
    int result = -1;

    while (l <= r) {
        int m = l + (r - l) / 2;
        if (nums[m] > target) {
            result = m;
            r = m - 1;
        } else {
            l = m + 1;
        }
    }
    return result;
}

int main() {
    int n;
    cin >> n;

    vector<long> nums;
    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        nums.push_back(num);
    }

    vector<long> towers;
    for (long &num : nums) {
        // binary search for it
        long tower_idx = bs(towers, num);
        if (tower_idx == -1) {
            towers.push_back(num);
        } else {
            towers[tower_idx] = num;
        }
    }

    cout << towers.size() << endl;
}