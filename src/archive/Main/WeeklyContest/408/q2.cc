#include <vector>
using namespace std;

bool isPrime(int num) {
    if (num <= 1) return false;
    for (int i = 2; i <= sqrt(num); ++i) {
        if (num % i == 0) return false;
    }
    return true;
}

class Solution {
  public:
    int nonSpecialCount(int l, int r) {
        int upper_limit = sqrt(r) + 1;
        vector<int> primes;

        // Find all prime numbers up to upper_limit
        for (int i = 2; i <= upper_limit; ++i) {
            if (isPrime(i)) {
                primes.push_back(i);
            }
        }

        vector<int> special_numbers;
        for (int prime : primes) {
            int special_number = prime * prime;
            if (special_number >= l && special_number <= r) {
                special_numbers.push_back(special_number);
            }
        }

        int total_numbers = r - l + 1;
        int special_count = special_numbers.size();

        return total_numbers - special_count;
    }
};