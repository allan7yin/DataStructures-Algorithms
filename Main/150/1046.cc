#include <queue>
#include <vector>
using namespace std;

class Solution {
  public:
    int lastStoneWeight(vector<int> &stones) {
        priority_queue<int> mh;
        for (int &stone : stones) {
            mh.push(stone);
        }

        while (mh.size() > 1) {
            int f = mh.top();
            mh.pop();
            int s = mh.top();
            mh.pop();
            if (f != s) {
                mh.push(f - s);
            }
        }
        return mh.empty() ? 0 : mh.top();
    }
};