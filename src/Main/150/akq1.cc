#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int computeDifference(const vector<int> deck) {
    int n = deck.size();
    int s = 0;
    int m = 0;
    bool left = true;
    bool sturn = true;

    deque<int> cards(deck.begin(), deck.end());

    while (!cards.empty()) {
        int top = 0;
        if (left) {
            top = cards.front();
            cards.pop_front();
        } else {
            top = cards.back();
            cards.pop_back();
        }
        if (sturn) {
            s += top;
        } else {
            m += top;
        }
        sturn = !sturn;
        if (top % 3 == 0) left = !left;
    }
    return s - m;
}

int main() {
    vector<int> deck = {3, 7, 2, 6, 5};
    cout << computeDifference(deck) << endl;
}