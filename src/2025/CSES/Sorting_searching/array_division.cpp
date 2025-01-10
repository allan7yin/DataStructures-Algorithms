#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>

using namespace std;

/*
This has time complexity constraints n <= 10^5
- immediately should signal something like binary search, or some < nlogn solution.

- we binary search for this max sum, then greedily see if it is valid
*/

bool is_valid(vector<int> &nums, long long maxCost, int k) {
    int parts = 1;
    long long cost = 0;
    for (int i = 0; i < nums.size(); i++) {
        cost += nums[i];
        if (cost > maxCost) {
            parts++;
            cost = nums[i];
            if (parts > k) return false;
        }
    }

    return true;
}

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    // find max sum k length subarray -> linear search
    long long left = *max_element(nums.begin(), nums.end());
    long long right = accumulate(nums.begin(), nums.end(), 0LL); // !!!!!! to create long long , need the LL, otherwise overflow

    // binary search from 1 to right, with each value m -> check if valid greedily

    long long result = -1;
    while (left <= right) {
        long long m = left + (right - left) / 2;
        if (is_valid(nums, m, k)) {
            result = m;
            right = m - 1;
        } else {
            left = m + 1;
        }
    }

    cout << result << endl;
    return 0;
}
