#include <iostream>
#include <utility>
#include <vector>

using namespace std;

long long find_median(vector<long long> &nums) {
    if (nums.size() % 2 == 1) {
        size_t m = nums.size() / 2;
        return nums[m];
    } else {
        size_t m1 = nums.size() / 2;
        size_t m2 = nums.size() / 2 - 1;
        return (nums[m1] + nums[m2]) / 2;
    }
}

int main() {
    int n;
    cin >> n;

    vector<long long> nums;
    for (int i = 0; i < n; i++) {
        long long num;
        cin >> num;
        nums.push_back(num);
    }

    sort(nums.begin(), nums.end());

    long long med = find_median(nums);
    long long cost = 0;
    for (long long &num : nums) {
        cost += abs(num - med);
    }

    cout << cost << endl;
}
