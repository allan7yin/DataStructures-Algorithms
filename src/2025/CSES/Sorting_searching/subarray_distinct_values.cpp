#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

/*
My first thought is this is some two-pointer question -> I was right
*/

long long f(vector<int> &nums, unordered_map<int, int> &mp, int k) {
    long long count = 0;
    for (int l = 0, r = 0; r < nums.size(); r++) {
        mp[nums[r]]++;
        while (mp.size() > k) {
            mp[nums[l]]--;
            if (mp[nums[l]] == 0) {
                mp.erase(nums[l]);
            }

            l++;
        }

        count += (r - l + 1); // + 1 since if r = l, should + 1
    }

    return count;
}

int main() {
    int n, k;
    cin >> n >> k;

    unordered_map<int, int> mp;

    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    long long first = f(nums, mp, k);
    mp.clear();
    // long long second = f(nums, mp, k);

    cout << first << endl;
}