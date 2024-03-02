#include <vector>
using namespace std;

class Solution {
public:
  vector<int> sortedSquares(vector<int> &nums) {
    // square the negatives and push into new vector -> iterate backwards
    // through this left with 2 sorted vectors of positive numbers -> merge ->
    // O(n)
    vector<int> result;
    vector<int> temp;
    int index1 = nums.size() - 1;
    for (int i = 0; i < nums.size(); i++) {
      if (nums[i] < 0) {
        temp.push_back(nums[i]);
      } else {
        index1 = i;
        break;
      }
    }
    int index2 = index1 - 1;

    while (index1 < nums.size() && index2 >= 0) {
      if (nums[index1] * nums[index1] < temp[index2] * temp[index2]) {
        result.push_back(nums[index1] * nums[index1]);
        index1++;
      } else {
        result.push_back(temp[index2] * temp[index2]);
        index2--;
      }
    }

    // add the leftovers
    int copy = index1;
    while (index1 < nums.size()) {
      result.push_back(nums[index1] * nums[index1]);
      index1++;
    }

    while (index2 >= 0) {
      result.push_back(temp[index2] * temp[index2]);
      index2--;
    }
    return result;
  }
};
