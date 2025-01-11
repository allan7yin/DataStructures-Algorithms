#include <algorithm>
#include <iostream>
#include <set>
#include <vector>

using namespace std;

/*
Some things we notice:
(1) 1 <= k <= n <= 2*10^5 -> we need < n^2 solution
- lloking like nlogn sol? iterate through vector -> for each subarray of length
k. find median?
- question is how to maintain sorted window, or find median in logn time

KEY !!! To maintain median of dynamic set of values, maintain one minheap for
the upper half and one maxheap for lower half

-> actually, 2 pqs is not good for us for the simple reason, we need to evict nums[l] immediately.
Leaving it in affects the size of pq, and so we need to look for another solution

-> maintain 2 multi-sets, one for bottom half and another for the upper half
*/
int main() {
    int n, k;
    cin >> n >> k;

    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    multiset<int> upper;
    multiset<int> lower;
    vector<int> medians;

    auto rebalance = [&]() {
        while (lower.size() > upper.size() + 1) {
            auto it = prev(lower.end());
            upper.insert(*it);
            lower.erase(it);
        }
        while (upper.size() > lower.size()) {
            auto it = upper.begin();
            lower.insert(*it);
            upper.erase(it);
        }
    };

    auto get_median = [&]() -> int {
        rebalance();
        return *prev(lower.end());
    };

    for (int i = 0; i < n; i++) {
        if (lower.empty() || nums[i] <= *prev(lower.end())) {
            lower.insert(nums[i]);
        } else {
            upper.insert(nums[i]);
        }

        if (i >= k) {
            int evict = nums[i - k];
            if (lower.count(evict)) {
                lower.erase(lower.find(evict)); // Erase one instance, need to use iterator
            } else {
                upper.erase(upper.find(evict));
            }
        }

        if (i >= k - 1) {
            medians.push_back(get_median());
        }
    }

    for (int median : medians) {
        cout << median << " ";
    }
    cout << endl;

    return 0;
}
