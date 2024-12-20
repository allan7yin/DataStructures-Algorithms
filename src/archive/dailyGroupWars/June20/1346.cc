class Solution {
public:
  bool checkIfExist(vector<int> &arr) {
    // sort(arr.begin(), arr.end(), greater<int>());
    unordered_set<int> seen;
    for (int num : arr) {
      if (seen.find(num * 2) != seen.end()) {
        return true;
      } else if ((num % 2 == 0) && (seen.find(num / 2) != seen.end())) {
        return true;
      }
      seen.insert(num);
    }
    return false;
  }
};