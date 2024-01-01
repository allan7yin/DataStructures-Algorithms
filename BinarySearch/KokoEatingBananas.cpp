#include <vector>

using namespace std;

class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int i = 1;
        int j = -1;
        for (int &num: piles) {
            j = max(j, num);
        }
        minCount = j;

        // binary search
        dnc(piles, h, i, j);
        return minCount;
    }

    void dnc(vector<int> &piles, int h, int start, int end) {
        if (end >= start) {
            int mid = start + (end-start)/2;
            long int hours = time_needed(piles, mid);
            if (hours <= h) {
                minCount = min(mid,minCount);
                dnc(piles, h, start, mid - 1);
            } else {
                dnc(piles, h, mid + 1, end);
            }
        }
    }

    long int time_needed(vector<int> &piles, int speed) {
        long int count = 0;
        for (int &num: piles) {
            count += ceil((double)num/speed);
        }
        return count;
    }
private:
    int minCount;
};

int main() {
    Solution sol;
    vector<int> piles = {3,6,7,11};
    sol.minEatingSpeed(piles,8);
}