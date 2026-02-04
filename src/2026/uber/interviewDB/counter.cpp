#include <deque>
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

/*
Implement a Counter class. Each element added to the Counter has an expiration time (time to live).
The expiration window is given during Counter initialization.

You are required to implement three functions:

put(time, element): adds an element to the Counter
get_count(time, element): returns the current valid count of the specified element in the Counter
get_total_count(time): returns the total count of all valid elements currently in the Counter
Example:

counter(window=10)
time 1: counter.put(time, 'a')
time 3: counter.put(time, 'a')
time 5: counter.put(time, 'b')
time 6: counter.get_count('a') -> 2
time 6: counter.get_total_count() -> 3
time 12: counter.get_count('a') -> 1
time 12: counter.get_total_count() -> 2
*/

template <typename T>
void print_vector(const vector<T> &res) {
    for (const auto &val : res) {
        cout << val << " ";
    }
    cout << endl;
}

class Counter {
  private:
    int total = 0;
    int ttl;
    unordered_map<char, int> fmp; // maps character to count of it in the counter
    deque<pair<char, int>> q;     // queue of character,time pairs pushed to the counter

  public:
    Counter(int ttl) : ttl(ttl) {}
    void put(int time, char element) {
        q.push_back({element, time});
        fmp[element]++;
        total++;
    }

    int get_count(int time, char element) {
        // first check if we need to pop anything from the front of the q
        while (!q.empty() && q.front().second < time - this->ttl) {
            auto [e, t] = q.front();
            fmp[e]--;
            total--;
            q.pop_front();
        }

        return fmp[element];
    }

    int get_total_count(int time) {
        while (!q.empty() && q.front().second < time - this->ttl) {
            auto [t, e] = q.front();
            fmp[e]--;
            total--;
            q.pop_front();
        }

        return total;
    }
};

int main() {
    Counter counter(10);

    // time 1: put('a')
    counter.put(1, 'a');

    // time 3: put('a')
    counter.put(3, 'a');

    // time 5: put('b')
    counter.put(5, 'b');

    // time 6: get_count('a') -> 2
    cout << "time 6 get_count('a') = " << counter.get_count(6, 'a') << " (expected 2)\n";

    // time 6: get_total_count() -> 3
    cout << "time 6 get_total_count() = " << counter.get_total_count(6) << " (expected 3)\n";

    // time 12: get_count('a') -> 1
    cout << "time 12 get_count('a') = " << counter.get_count(12, 'a') << " (expected 1)\n";

    // time 12: get_total_count() -> 2
    cout << "time 12 get_total_count() = " << counter.get_total_count(12) << " (expected 2)\n";

    return 0;
}
