#include <vector>
using namespace std;

class Solution {
  public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> result;
        for (int i = 1; i <= numRows; i++) {
            result.push_back(generateRow(i));
        }
        return result;
    }

  private:
    vector<int> generateRow(int rowIndex) {
        if (rowIndex == 1) return {1};
        if (rowIndex == 2) return {1, 1};
        vector<int> prev = generateRow(rowIndex - 1);
        vector<int> cur = {1};
        for (int i = 0; i < prev.size() - 1; i++) {
            int v = prev[i] + prev[i + 1];
            cur.push_back(v);
        }
        cur.push_back(1);
        return cur;
    }
};