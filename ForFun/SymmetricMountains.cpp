#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<int> symmetricMountains(int n, vector<int> nums) {
        vector<int> result;
        result.push_back(0);
        vector<vector<int>> matrix(n, vector<int> (n, 0));
        
        // now, we populate result 
        int count = 1;
        for (int i = 0; i < nums.size(); i++) {
            if (count == nums.size()) {
                break;
            }
            int l = 0;
            int r = count;
            int temp = INT_MAX;
            
            while (r < nums.size()) {
                int value = abs(nums[r] - nums[l]) + matrix[l+1][r-1];
                matrix[l][r] = value;
                temp = min(temp, value);
                r++;
                l++;
            }
            result.push_back(temp);
            count++;
        }
        return result;
    }
};

int main() {
    Solution sol;
    vector<int> numbers = {1,3,5, 6};
    int num;
    
    while (std::cin >> num) {
        numbers.push_back(num);
    }

    vector<int> result = sol.symmetricMountains(numbers.size(), numbers);
    
    for (auto &num:result) {
        cout << num << endl;
    }
}