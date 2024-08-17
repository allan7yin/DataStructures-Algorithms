#include <cmath>
#include <iostream>
#include <numeric>
#include <vector>

using namespace std;

/*
2 9 1 2 7

-> After sorting this, we get: 1 2 2 7 9

*/

long long missingCoinSum(vector<long long> &nums) {
    sort(nums.begin(), nums.end());
    long long minVal = 1;
    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] > minVal) return minVal;
        minVal += nums[i];
    }
    return minVal;
}

int main() {
    int n;
    cin >> n;

    vector<long long> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    cout << missingCoinSum(nums) << endl;
}