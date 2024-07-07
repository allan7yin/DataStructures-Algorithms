#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
  unordered_map<int, int> fmap;

public:
  vector<int> relativeSortArray(vector<int> &arr1, vector<int> &arr2) {
    // Build the comparison hashmap, mapping num to index
    for (int i = 0; i < arr2.size(); i++) {
      fmap[arr2[i]] = i;
    }

    vector<int> notIn;
    // Separate arr1 into elements in fmap and not in fmap
    vector<int> inMap;
    for (int num : arr1) {
      if (fmap.find(num) != fmap.end()) {
        inMap.push_back(num);
      } else {
        notIn.push_back(num);
      }
    }

    // Sort the elements in fmap according to their mapped values
    sort(inMap.begin(), inMap.end(), [this](int a, int b) {
      return fmap[a] < fmap[b];
    });

    // Sort the elements not in fmap in ascending order
    sort(notIn.begin(), notIn.end());

    // Combine both sorted vectors
    inMap.insert(inMap.end(), notIn.begin(), notIn.end());

    return inMap;
  }
};