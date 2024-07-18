#include <climits>
#include <iostream>
using namespace std;
/*
Input: arr[] = {40, 20, 30, 10, 30}
Output: 26000
Explanation:There are 4 matrices of dimensions 40×20, 20×30, 30×10, 10×30.
Let the input 4 matrices be A, B, C and D.
The minimum number of  multiplications are obtained by
putting parenthesis in following way (A(BC))D.
The minimum is 20*30*10 + 40*20*10 + 40*10*30

Input: arr[] = {1, 2, 3, 4, 3}
Output: 30
Explanation: There are 4 matrices of dimensions 1×2, 2×3, 3×4, 4×3.
Let the input 4 matrices be A, B, C and D.
The minimum number of multiplications are obtained by
putting parenthesis in following way ((AB)C)D.
The minimum number is 1*2*3 + 1*3*4 + 1*4*3 = 30
*/

// solution is similar to how you would solve minimum cost tree from leaf values
// recursively, we split the interval in half, and look for the minimum from
// there

int dp[100][100];
// top-down memoized recursion
int fmem(int p[], int i, int j) {
  // base
  if (i == j) {
    return 0;
  }

  // check if memoized
  if (dp[i][j] != -1)
    return dp[i][j];

  dp[i][j] = INT_MAX;
  // every possible split
  for (int k = i; k < j; k++) {
    dp[i][j] = min(dp[i][j], (p[i - 1] * p[k] * p[j]) + fmem(p, i, k) +
                                 fmem(p, k + 1, j));
  }
  return dp[i][j];
}

// naive recursive solution
int fnaive(int p[], int i, int j) {
  // base
  if (i == j) {
    return 0;
  }

  int minOps = INT_MAX;
  // every possible split
  for (int k = i; k < j; k++) {
    minOps = min(minOps, (p[i - 1] * p[k] * p[j]) + fnaive(p, i, k) +
                             fnaive(p, k + 1, j));
  }
  return minOps;
}

// Driver Code
int main() {
  int arr[] = {1, 2, 3, 4, 3};
  int N = sizeof(arr) / sizeof(arr[0]);
  // Function call
  memset(dp, -1, sizeof(dp));
  cout << "Minimum number of multiplications is " << fmem(arr, 1, N - 1)
       << endl;
  return 0;
}
