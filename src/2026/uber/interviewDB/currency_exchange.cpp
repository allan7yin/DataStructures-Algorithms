#include <deque>
#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

/*
(GBP, EUR, 10) - read as "1 GBP equals 10 EUR"
(EUR, USD, 1.1) - "1 EUR equals 1.1 USD"
(10, GBP, USD) => ? - "10 GBP equals how many USD?"
Answer: 110
Explanation: 10 GBP = 10 x (10 EUR) = 10 x (10 x (1.1 USD)) = 110 USD

Very similar to the Jane street int -> create graph of currencies with adjacnecy list representation -> traverse with visited list

*/
template <typename T>
void print_vector(const vector<T> &res) {
    for (const auto &val : res) {
        cout << val << " ";
    }
    cout << endl;
}

unordered_map<string, vector<pair<string, double>>> cmp; // currency conversion map -> currency : (currency, amount)

void record_exchange(string from, string to, double amount) {
    cmp[from].push_back({to, amount});
}

double compute_conversion(double amount, string from, string to) {
    deque<pair<string, double>> frontier;
    unordered_set<string> seen;
    seen.insert(from);
    frontier.push_back({from, amount}); // gbp, 10

    while (!frontier.empty()) {
        auto [curr, curr_amount] = frontier.front();
        frontier.pop_front();

        if (curr == to) {
            // reached target currency
            return curr_amount;
        }

        for (auto &neighbour : cmp[curr]) {
            if (seen.count(neighbour.first) == 0) {
                // this currency has not been visited yet, push onto the queue and marked as visited
                frontier.push_back({neighbour.first, curr_amount * neighbour.second}); // eur, 100
                seen.insert(neighbour.first);
            }
        }
    }

    return -1;
}

int main() {
    record_exchange("GBP", "EUR", 10);
    record_exchange("EUR", "USD", 1.1);
    record_exchange("USD", "JPY", 150);
    record_exchange("USD", "CAD", 1.35);

    cout << compute_conversion(10, "GBP", "USD") << " (expected 110)\n";
    cout << compute_conversion(2, "GBP", "JPY") << " (expected 3300)\n";
    cout << compute_conversion(10, "USD", "CAD") << " (expected 13.5)\n";
    cout << compute_conversion(10, "USD", "USD") << " (expected 10)\n";

    record_exchange("A", "B", 2);
    record_exchange("A", "C", 5);
    record_exchange("C", "B", 1);
    cout << compute_conversion(1, "A", "B") << " (expected 2 or 5)\n";

    record_exchange("X", "Y", 2);
    record_exchange("Y", "Z", 3);
    record_exchange("Z", "X", 0.5);
    cout << compute_conversion(1, "X", "Z") << " (expected 6)\n";

    cout << compute_conversion(10, "USD", "GBP") << " (expected -1)\n";
}

/*
❯ ./curr
110 (expected 110)
3300 (expected 3300)
13.5 (expected 13.5)
10 (expected 10)
2 (expected 2 or 5)
6 (expected 6)
-1 (expected -1)

*/