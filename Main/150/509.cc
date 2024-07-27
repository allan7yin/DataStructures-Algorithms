class Solution {
public:
  int fib(int n) {
    if (n == 1)
      return 1;
    int second = 1;
    int first = 0;
    int result = 0;
    for (int i = 1; i < n; i++) {
      result = first + second;
      first = second;
      second = result;
    }
    return result;
  }
};
