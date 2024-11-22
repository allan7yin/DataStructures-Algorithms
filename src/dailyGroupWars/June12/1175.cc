class Solution {
public:
  int numPrimeArrangements(int n) {
    int m = (int)(1e9 + 7);
    int primes = 0;
    for (int i = 1; i <= n; ++i) {
      if (isPrime(i))
        primes++;
    }
    return ((factorial(primes, m) % m) * (factorial(n - primes, m) % m) % m);
  }

private:
  bool isPrime(int n) {
    if (n <= 1)
      return false;
    for (int i = 2; i * i <= n; ++i) {
      if (n % i == 0)
        return false;
    }
    return true;
  }

  long long factorial(int n, int m) {
    long long result = 1;
    while (n > 0) {
      result = ((result % m) * (n % m)) % m;
      n--;
    }
    return result;
  }
};
