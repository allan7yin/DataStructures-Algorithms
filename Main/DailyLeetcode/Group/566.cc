#include <vector>
using namespace std;

class Solution {
  public:
    vector<vector<int>> matrixReshape(vector<vector<int>> &mat, int r, int c) {
        vector<vector<int>> newShape(r, vector<int>(c, 0));
        int orows = mat.size();
        int oc = mat[0].size();

        if (orows * oc != r * c) return mat;
        r--;
        c--;
        int c2 = c;
        int r2 = r;
        for (int i = orows - 1; i >= 0; i--) {
            for (int j = oc - 1; j >= 0; j--) {
                if (c2 < 0) {
                    c2 = c;
                    r2--;
                }

                if (r2 < 0) {
                    break;
                }
                newShape[r][c] = mat[i][j];
                c--;
            }
        }
        return newShape;
    }
};