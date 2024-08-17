#include <algorithm>
#include <iostream>
#include <vector>

void f(std::vector<std::pair<int, int>> &nums, int target) {
    int l = 0, r = nums.size() - 1;
    while (l < r) {
        int temp = nums[l].first + nums[r].first;
        if (temp == target) {
            std::cout << nums[l].second + 1 << " " << nums[r].second + 1 << std::endl;
            return;
        } else if (temp > target) {
            r--;
        } else {
            l++;
        }
    }
    std::cout << "IMPOSSIBLE" << std::endl;
}

int main() {
    int n, x;
    std::cin >> n >> x;
    std::vector<std::pair<int, int>> nums(n);

    for (int i = 0; i < n; i++) {
        std::cin >> nums[i].first;
        nums[i].second = i;
    }

    std::sort(nums.begin(), nums.end());
    f(nums, x);
}