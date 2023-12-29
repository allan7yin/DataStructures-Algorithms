#include <vector>
#include <stack>

using namespace std;
/*
    - create pair of position and speed and sort in decreasing order 
    - then, for each pair, we push the needed time for each car to finish onto the stack 
    - if the top of the stack is less than the bottom of the stack, pop from the stack -> simiulates 2 cars joining into one 
*/
class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();
        int num_pools = 1;

        vector<pair<int, double>> pos_speeds;
        for (int i = 0; i < n; i++) {
            double time = (double)(target - position[i]) / speed[i];
            pos_speeds.push_back(make_pair(position[i], time));
        }

        sort(pos_speeds.begin(), pos_speeds.end());
        double slowest = pos_speeds[n-1].second;
        for (int i = n-1; i >= 0; i--) {
            if (pos_speeds[i].second > slowest) {
                num_pools++;
                slowest = pos_speeds[i].second;
            }
        }

        return num_pools;
    }
};

int main() {
    Solution sol;
    vector<int> position = {6,8};
    vector<int> speed = {3,2};
    sol.carFleet(10, position, speed);
}