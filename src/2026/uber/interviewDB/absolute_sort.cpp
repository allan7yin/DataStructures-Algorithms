#include <cstdlib>
#include <iostream>
#include <vector>
using namespace std;

/*
Given a sorted array of integers, reorder the array so that the elements are sorted by their absolute values in increasing order.
If there are ties (i.e., numbers with the same absolute value), place the negative number before the positive number.
*/
template <typename T>
void print_vector(const vector<T> &res) {
    for (const auto &val : res) {
        cout << val << " ";
    }
    cout << "\n";
}

// PART 1
vector<int> reorder_array(vector<int> &nums) {
    // find the index where we jump from negatives to positive
    int index = 0;
    int n = nums.size();
    for (int i = 0; i < n - 1; i++) {
        if (nums[i] < 0 && nums[i + 1] >= 0) {
            index = i + 1;
        }
    }

    vector<int> negatives;
    vector<int> positives;
    for (int i = index - 1; i >= 0; i--)
        negatives.push_back(nums[i]);
    for (int i = index; i < n; i++)
        positives.push_back(nums[i]);

    // merge the 2 vectors
    vector<int> result;
    int l = 0, r = 0;
    while (l < negatives.size() || r < positives.size()) {
        if (l < negatives.size() && r < positives.size()) {
            // push the min between the 2 arrays
            int left = abs(negatives[l]);
            int right = abs(positives[r]);
            if (left <= right) {
                result.push_back(negatives[l]);
                l++;
            } else {
                result.push_back(positives[r]);
                r++;
            }
        } else if (l < negatives.size()) {
            result.push_back(negatives[l]);
            l++;
        } else {
            result.push_back(positives[r]);
            r++;
        }
    }

    return result;
}

// PART 2 -> Find the k-th largest element (by the new absolute value order) ... so just iterate until you reach the kth index in the new array lol...
int k_largest(vector<int> &nums, int k) {
    if (k > nums.size()) return -1;
    return nums[k - 1];
}

int main() {
    vector<int> test = {-5, -4, -2, 0, 1, 2, 3};
    auto res = reorder_array(test);
    print_vector(res);
    cout << k_largest(res, 4);
}
