#include <vector>
using namespace std;

class Solution {
public:
  vector<vector<int>> generate(int numRows) {
    vector<vector<int>> pascal;
    vector<int> first = {1};
    vector<int> second = {1, 1};
    pascal.push_back(first);
    if (numRows == 1) {
      return pascal;
    }
    pascal.push_back(second);
    if (numRows == 2) {
      return pascal;
    }
    for (int i = 2; i < numRows; i++) {
      vector<int> row;
      row.push_back(1);

      for (int j = 0; j < pascal.back().size() - 1; j++) {
        row.push_back(pascal.back()[j] + pascal.back()[j + 1]);
      }
      row.push_back(1);
      pascal.push_back(row);
    }
    return pascal;
  }
};