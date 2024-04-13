#include <vector>
#include <util.h>
using namespace std;

/*
 * We solve this problem with memoization, top-down. This is a DP question
 * - When we are asked to solve these kinds of questions, we use caching 
 *   as a way of reducing time complexity 
 */
class Solution {
public:
  int maximalSquare(vector<vector<char>> &matrix) {
    // create the cache 
    int n = matrix.size();
    int m = matrix[0].size();
    // the below is for rectangle, the idea is similar, you cache both sides
    // vector<vector<pair<int, int>>> cache(n, vector<pair<int, int>> (m));
    vector<vector<int>> cache(n + 1, vector<int> (m + 1, 0));
    int maxDim = 0;
    // build top down, so iterate in reverse of the matrix 
    for (int i = n-1; i >= 0; i--) {
      for (int j = m-1; j >= 0; j--) {
        if (matrix[i][j] == '1') {
          cache[i][j] = 1 + min(cache[i + 1][j],
              min(cache[i][j+1], cache[i+1][j+1]));
            
          maxDim = max(maxDim, cache[i][j]);
        }
      }
    }

    return maxDim * maxDim;
  }
};
