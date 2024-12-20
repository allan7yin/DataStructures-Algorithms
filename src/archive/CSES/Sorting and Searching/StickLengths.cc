#include <cmath>
#include <iostream>
#include <numeric>
#include <vector>

using namespace std;
/*
Input:

5
2 3 1 5 2
sorted array: 1 2 2 3 5 ->
-> initial idea: average is 13/5 -> choose between 2 and 3 -> choose the one of minimum distance
-> mean is actually not as good a metric as median
Output:

5
*/
long long minStickLengths(vector<long long> &nums) {
    int n = nums.size();
    sort(nums.begin(), nums.end());
    long long median = nums[n / 2];

    long long total_cost = 0;
    for (int i = 0; i < n; i++) {
        total_cost += abs(nums[i] - median);
    }

    return total_cost;
}

int main() {
    int x;
    cin >> x;
    vector<long long> nums(x);

    for (int i = 0; i < x; i++) {
        cin >> nums[i];
    }

    cout << minStickLengths(nums) << endl;
}