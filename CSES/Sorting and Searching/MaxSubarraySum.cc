#include <climits>
#include <iostream>
#include <vector>

using namespace std;

long long maxSubArray(vector<long long> &nums) {
    int n = nums.size();
    long long maxSum = nums[0];
    long long curSum = 0;

    for (int i = 0; i < n; i++) {
        curSum = max(curSum, 0LL);
        curSum += nums[i];
        maxSum = max(maxSum, curSum);
    }
    return maxSum;
}
// this is too slow -> need a linear time solution for this problem
// int maxSubSum(vector<int> prefixSum) {
//     int n = prefixSum.size();
//     int maxSum = INT_MIN;

//     for (int i = 0; i < n; i++) {
//         for (int j = i - 1; j >= 0; j--) {
//             maxSum = max(maxSum, prefixSum[i] - prefixSum[j]);
//         }
//     }
//     return maxSum;
// }

// solve this with a prefix sum
int main() {
    int n;
    cin >> n;
    vector<long long> nums(n);

    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    cout << maxSubArray(nums) << endl;
}