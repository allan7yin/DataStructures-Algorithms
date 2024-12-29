#include <climits>
#include <iostream>
#include <utility>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<long long> nums;
    for (int i = 0; i < n; i++) {
        long long num;
        cin >> num;
        nums.push_back(num);
    }

    long long maxVal = LLONG_MIN;
    long long sum = 0;

    for (int r = 0; r < nums.size(); r++) {
        sum += nums[r];
        maxVal = max(maxVal, sum);

        if (sum < 0) {
            sum = 0;
        }
    }

    cout << maxVal << endl;
}

// 10
//  99 -59 31 83 -79 64 -20 -87 40 -31