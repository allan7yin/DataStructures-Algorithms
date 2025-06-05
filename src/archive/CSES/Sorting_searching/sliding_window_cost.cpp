#include <iostream>
#include <set>
#include <vector>

using namespace std;

/*
n <= 10^5 -> nlogn solution works. Use a multiset as insertion and erase is log(n) -> implemented via slf-balancing tree
*/
int main() {
    int n, k;
    cin >> n >> k;

    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    multiset<int> window;

    auto get_median = [&]() -> int {
        auto it = window.begin();
        advance(it, (k - 1) / 2); // Median is at (k-1)/2 index (0-based)
        return *it;
    };
    for (int i = 0; i < n; i++) {
        window.insert(nums[i]);
        if (i < k - 1) {
            continue;
        }

        if (i >= k) {
            // evict
            auto it = window.find(nums[i - k]);
            if (it != window.end()) {
                window.erase(it);
            }
        }

        // print the cost
        int cost = 0;
        int median = get_median();
        for (int x : window) {
            cost += abs(x - median);
        }

        cout << cost << " ";
    }

    cout << endl;
}