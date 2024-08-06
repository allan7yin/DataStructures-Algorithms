#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;
/*
https://cses.fi/problemset/task/1621
*/

int distinctNumbers(vector<int> &nums) {
    int unique = 1;
    int prev = 0;
    sort(nums.begin(), nums.end());
    for (int i = 1; i < nums.size(); i++) {
        prev = nums[i - 1];
        if (nums[i] != prev) {
            unique++;
        }
    }
    return unique;

    // interestingly, the unordered set solution times out => seems hashing can become quite slow
    // unordered_set<int> mySet;
    // for (int &num : nums) {
    //     mySet.insert(num);
    // }
    // return mySet.size();
}

int main() {
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }

    cout << distinctNumbers(nums) << endl;

    return 0;
}