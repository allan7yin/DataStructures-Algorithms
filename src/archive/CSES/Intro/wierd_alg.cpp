#include <iostream>
#include <vector>

using namespace std;

int main() {
    long long n;
    cin >> n;
    vector<long long> nums = {n};
    while (nums.back() != 1) {
        long long last = nums.back();
        if (last % 2 == 0) {
            nums.push_back(last / 2);
        } else {
            nums.push_back(last * 3 + 1);
        }
    }

    for (int i = 0; i < nums.size(); i++) {
        cout << nums[i];
        if (i != nums.size() - 1) {
            cout << " ";
        }
    }
}