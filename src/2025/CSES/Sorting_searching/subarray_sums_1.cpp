#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

// given that the array is not sorted, cannot use 2 pointer approach
// also, sorting array will mess up the order -> need to use prefix sum
// not hard since x >= 1

int main() {
    int n, target;
    unordered_map<long long, long long> mp;
    mp[0] = 1;
    cin >> n >> target;

    long long sum = 0;
    long long count = 0;
    for (int i = 0; i < n; i++) {
        long val;
        cin >> val;

        sum += val;

        if (mp.find(sum - target) != mp.end()) {
            count += mp[sum - target];
        }

        mp[sum]++;
    }

    cout << count << endl;
}