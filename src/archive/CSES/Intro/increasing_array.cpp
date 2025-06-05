#include <iostream>
#include <string>
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

    long long cost = 0;
    int prev = -1;
    for (int i = 0; i < n; i++) {
        if (nums[i] < prev) {
            cost += (prev - nums[i]);
            nums[i] = prev;
        }
        prev = nums[i];
    }
    cout << cost << endl;
}