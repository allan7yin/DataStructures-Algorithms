#include <deque>
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

/*
Every day, millions of customers visit our website. Each customer has a unique ID that remains the same across all their visits.
There are two types of customers:

Recurrent visitors: Customers who have visited more than once.
One-time visitors: Customers who have visited only once so far.
Design a service that supports the following two operations:

postCustomerVisit(customerId): Records a visit from the customer with the given ID.
getFirstOneTimeVisitor(): Returns the ID of the first customer (in order of their first visit) who has visited only once up to now.
If there is no such customer, return an appropriate value (e.g., null).

Examples:

postCustomerVisit('A')
postCustomerVisit('B')
postCustomerVisit('C')
getFirstOneTimeVisitor() // should return 'A'

postCustomerVisit('D')
postCustomerVisit('E')
postCustomerVisit('C')
postCustomerVisit('D')
postCustomerVisit('C')
postCustomerVisit('A')
getFirstOneTimeVisitor() // should return 'E'
*/

unordered_map<char, int> fmp;
deque<char> q;

void postCustomerVisit(char customerId) {
    fmp[customerId]++;
    q.push_back(customerId);
}

char getFirstOneTimeVisitor() {
    while (!q.empty() && fmp[q.front()] > 1) {
        q.pop_front();
    }

    return q.front();
}

int main() {
    postCustomerVisit('A');
    postCustomerVisit('B');
    postCustomerVisit('C');
    cout << getFirstOneTimeVisitor() << endl; // should return 'A'

    postCustomerVisit('D');
    postCustomerVisit('E');
    postCustomerVisit('C');
    postCustomerVisit('D');
    postCustomerVisit('C');
    postCustomerVisit('A');
    cout << getFirstOneTimeVisitor() << endl; // should return 'B'
}