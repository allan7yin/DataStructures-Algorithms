class Solution {
public:
  int primePalindrome(int n) {
    if (n >= 9989900)
      return 100030001;
    if (n <= 2)
      return 2;
    if (n == 3)
      return 3;

    for (int i = n;; ++i) {
      if (isPalindrome(i) && isPrime(i)) {
        return i;
      }
    }
    return -1;
  }

private:
  bool isPalindrome(int n) {
    if (n < 0)
      return false;

    int original = n;
    int reversed = 0;
    while (n != 0) {
      int digit = n % 10;
      reversed = reversed * 10 + digit;
      n /= 10;
    }

    return original == reversed;
  }

  bool isPrime(int n) {
    if (n <= 1)
      return false;
    if (n <= 3)
      return true;
    if (n % 2 == 0 || n % 3 == 0)
      return false;
    for (int i = 5; i * i <= n; i += 6) {
      if (n % i == 0 || n % (i + 2) == 0)
        return false;
    }
    return true;
  }
};