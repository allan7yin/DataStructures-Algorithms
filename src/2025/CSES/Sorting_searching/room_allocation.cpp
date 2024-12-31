#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<tuple<int, int, int>> days(n);

    for (int i = 0; i < n; i++) {
        int start, end;
        cin >> start >> end;
        days[i] = {start, end, i};
    }

    sort(days.begin(), days.end(), [](auto &a, auto &b) {
        if (get<0>(a) == get<0>(b)) {
            return get<1>(a) < get<1>(b);
        }
        return get<0>(a) < get<0>(b);
    });

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    vector<int> roomAssignments(n);
    int roomCount = 0;

    for (auto &[start, end, index] : days) {
        if (!pq.empty() && pq.top().first < start) {
            int room = pq.top().second;
            pq.pop();
            pq.push({end, room});
            roomAssignments[index] = room;
        } else {
            roomCount++;
            pq.push({end, roomCount});
            roomAssignments[index] = roomCount;
        }
    }

    cout << roomCount << endl;
    for (int &room : roomAssignments) {
        cout << room << " ";
    }
}

/*
1 2
2 4
4 4

sort by start time -> maintain a mim heap of (end, room) -> then, we just check if earliest avail room can be used by current person's days
-> if yes, give it to them, otherwise, need new room
*/