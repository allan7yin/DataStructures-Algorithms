#include <iostream>
#include <utility>
using namespace std;

void numRounds2(vector<int> &nums, vector<pair<int, int>> swaps) {
    int n = nums.size();
    vector<int> ind(n + 1, 0);
    for (int i = 0; i < n; i++) {
        ind[nums[i]] = i;
    }

    int rounds = 1;
    for (int i = 1; i < n; i++) {
        if (ind[i] > ind[i + 1]) {
            rounds++;
        }
    }

    // 1 2 3 4
    // 1 4 3 2
    // this is the basic number of rounds, now, the rest of the pairs represent swaps
    for (auto &s : swaps) {
        int first_idx = s.first;
        int second_idx = s.second;
        int first_num = nums[first_idx];
        int second_num = nums[second_idx];

        // Check and update out-of-order pairs involving first_num and second_num
        auto checkPair = [&](int a, int b) {
            if (a > 0 && a <= n && b > 0 && b <= n) {
                if (ind[a] > ind[b])
                    rounds--;
                else
                    rounds++;
            }
        };

        // Remove the out-of-order effect before the swap
        checkPair(first_num - 1, first_num);
        checkPair(first_num, first_num + 1);
        checkPair(second_num - 1, second_num);
        checkPair(second_num, second_num + 1);

        // Perform the swap
        swap(nums[first_idx], nums[second_idx]);
        swap(ind[first_num], ind[second_num]);

        // Re-add the out-of-order effect after the swap
        checkPair(first_num - 1, first_num);
        checkPair(first_num, first_num + 1);
        checkPair(second_num - 1, second_num);
        checkPair(second_num, second_num + 1);

        cout << rounds << endl;
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> nums(n);

    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    vector<pair<int, int>> swaps;
    for (int i = 0; i < m; i++) {
        pair<int, int> s;
        cin >> s.first >> s.second;
        swaps.push_back(s);
    }

    numRounds2(nums, swaps);
}