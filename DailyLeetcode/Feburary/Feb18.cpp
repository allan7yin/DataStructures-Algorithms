#include <vector>
#include <queue>
using namespace std;
/*
    - We can first sort this by start value 
    - maintain 2 heaps 
        -> one for "free" meeting rooms -> always choose the smallest
        -> one for "used" meeting rooms -> do this by end time of that meeting, pop whenever done and add back to free meeting room 
    - maintain count of use for each room in a array -> contains pairs of (# of times used)
*/

class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        sort(meetings.begin(), meetings.end());
        priority_queue<long long, vector<long long>, greater<long long>> available;
        priority_queue<pair<long long, long long>, vector<pair<long long, long long>>, greater<pair<long long, long long>>> used;
        vector<long long> count(n,0);

        // initilaize free room 
        for (int i = 0; i < n; i++) {
            available.push(i);
        }

        for (int i = 0; i < meetings.size(); i++) {
            long long start = meetings[i][0];
            long long end = meetings[i][1];

            // finish meetings 
            while (!used.empty() && start >= used.top().first) {
                // so, the current star time is smaller than this finish time 
                pair<long long, long long> temp = used.top();
                used.pop();
                available.push(temp.second);
            }

            // no room is available 
            if (available.empty()) {
                pair<long long, long long> temp = used.top();
                used.pop();
                end = temp.first + (end - start);
                available.push(temp.second);
            }

            long long room = available.top();
            available.pop();
            used.push({end, room});
            count[room]++;
        }

        long long maxCount = 0;
        int result = 0;
        for (int i = n-1; i >= 0; i--) {
            if (count[i] >= maxCount) {
                maxCount = count[i];
                result = i;
            }
        }
        return result;
    }
};