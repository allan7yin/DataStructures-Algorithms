#include <iostream>
/*
No. 1010: Building bridges
Link: https://www.acmicpc.net/problem/1010
- This is a classic problem in co -> n on left, m on right: n!/(m-n)!
*/
int main() {
  int num_cases = 0;
  std::cin >> num_cases;

  int n = 0, m = 0;
  for (int i = 0; i < num_cases; i++) {
    std::cin >> n;
    std::cin >> m;
    int limit = m - n;
    int result = 1;
    for (m; m < limit; m--) {
      result *= m;
    }
    std::cout << result << std::endl;
  }
}
