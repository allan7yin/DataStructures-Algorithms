#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

/*
Similar to looking for subsarray sum == k.
*/
int main() {
    int n;
    cin >> n;

    vector<int> nums(n);
    unordered_map<int, int> mp;
    mp[0] = 1;
    long long count = 0;
    long long sum = 0;

    for (int i = 0; i < n; i++) {
        cin >> nums[i];

        sum += nums[i];
        // can't do sum % n, as if sum < 0, the remainder is also -, which is not what we want
        int rem = ((sum % n) + n) % n;

        if (mp.find(rem) != mp.end()) {
            count += mp[rem];
        }
        mp[rem]++;
    }

    cout << count << endl;
}