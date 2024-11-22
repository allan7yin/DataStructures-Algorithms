#include <queue>

using namespace std;

/*
- The idea: We want to use 2 heaps: a max heap and a min heap
- we keep these as balanced as possible, so that computing median is constant time
- when one of them is > 2 in size, we pop one from the larger one and move it into the smaller one
*/
class MedianFinder {
    priority_queue<int, vector<int>, greater<int>> minH;
    priority_queue<int> maxH;

  public:
    MedianFinder() {
    }

    void adjust() {
        // make sure difference in size is <= 1
        if (minH.size() > maxH.size() + 1) {
            // too many in minH (a.k.a more values > median than less than)
            int top = minH.top();
            minH.pop();
            maxH.push(top);
        } else if (maxH.size() > minH.size() + 1) {
            int top = maxH.top();
            maxH.pop();
            minH.push(top);
        }
    }
    void addNum(int num) {
        if (!maxH.empty() && num > maxH.top()) {
            minH.push(num);
        } else {
            maxH.push(num);
        }

        this->adjust();
    }

    double findMedian() {
        // even or not
        double median = 0;
        if (minH.size() > maxH.size()) {
            median = minH.top();
        } else if (maxH.size() > minH.size()) {
            median = maxH.top();
        } else {
            median = ((double)minH.top() + (double)maxH.top()) / (double)2;
        }
        return median;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */