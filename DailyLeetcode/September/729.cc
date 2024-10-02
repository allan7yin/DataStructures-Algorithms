#include <set>
#include <vector>

using namespace std;

/*
- binary search question
[10, 20], [20,30]
-> [15, 25]
if any current boooking begins at <= 15, and ends at >= 25, can't
so, maintain 2 lists, one for start times and one for end, and binary search

-> need increasing order collection -> use a set, no need to binary search, use lower_bound and upper_bound
*/

class MyCalendar {
    set<int> startTimes;
    set<int> endTimes;

  public:
    MyCalendar() {
    }

    bool book(int start, int end) {
        auto l = startTimes.lower_bound(start);
        auto r = endTimes.upper_bound()
    }
};
