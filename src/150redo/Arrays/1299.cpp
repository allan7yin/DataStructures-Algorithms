#include <vector>
using namespace std;

class Solution {
  public:
    vector<int> replaceElements(vector<int> &arr) {
        int n = arr.size();
        int largest = arr[n - 1];
        for (int i = n - 1; i >= 0; i--) {
            if (i == n - 1) {
                arr[i] = -1;
                continue;
            }

            int temp = arr[i];
            arr[i] = largest;
            largest = max(largest, temp);
        }
        return arr;
    }
};