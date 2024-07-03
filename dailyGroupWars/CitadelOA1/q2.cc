#include <vector>
using namespace std;

vector<int> f(vector<int> arr) {
  int mx = 0, n = arr.size();
  for (auto num : arr)
    mx |= num;
  vector<int> res;
  // x = 101011
  for (int x = 0; x <= mx; x++) {
    int val = 0;
    for (int i = 0; i < n; i++) {
      if ((arr[i] & x) == arr[i]) {
        // arr[i] is a submask
        val |= arr[i];
      }
    }
    if (val == x)
      res.push_back(x);
  }
  return res;
}