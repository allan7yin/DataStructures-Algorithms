class Solution {
public:
  int findSpecialInteger(vector<int> &arr) {
    int threshold = arr.size() / 4;
    unordered_map<int, int> fmap;
    for (int &num : arr) {
      fmap[num]++;
      if (fmap[num] > threshold) {
        return num;
      }
    }
    return 0;
  }
};