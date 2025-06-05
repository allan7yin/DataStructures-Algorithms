#include <iostream>
#include <utility>
#include <vector>

using namespace std;

// cannot brute force this -> n <= 10^5
int main() {
    int n;
    cin >> n;

    vector<int> nums;
    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        nums.push_back(num);
    }

    sort(nums.begin(), nums.end());

    long long sum = 1;
    for (int &num : nums) {
        if (num > sum) {
            break;
        } else {
            sum += num;
        }
    }
    cout << sum << endl;
}