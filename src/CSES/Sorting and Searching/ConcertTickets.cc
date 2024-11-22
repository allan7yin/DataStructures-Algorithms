#include <iostream>
#include <set>
#include <vector>
using namespace std;

/*
https://cses.fi/problemset/task/1091
*/

vector<int> matchTickets(vector<int> &prices, vector<int> &offers) {
    multiset<int> ticketPrices(prices.begin(), prices.end());
    vector<int> result;

    for (int offer : offers) {
        auto it = ticketPrices.upper_bound(offer);
        if (it == ticketPrices.begin()) {
            result.push_back(-1);
        } else {
            --it;
            result.push_back(*it);
            ticketPrices.erase(it);
        }
    }

    return result;
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> prices(n);
    vector<int> customerOffer(m);

    for (int i = 0; i < n; i++) {
        cin >> prices[i];
    }

    for (int i = 0; i < n; i++) {
        cin >> customerOffer[i];
    }

    auto result = matchTickets(prices, customerOffer);
    for (int &p : result) {
        cout << p << endl;
    }
}
