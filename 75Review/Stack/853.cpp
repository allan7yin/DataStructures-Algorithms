#include <stack>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
  public:
    int carFleet(int target, vector<int> &position, vector<int> &speed) {
        unordered_map<int, double> arrivals;
        for (int i = 0; i < position.size(); i++) {
            double time = ((double)target - (double)position[i]) / speed[i];
            arrivals[position[i]] = time;
        }

        sort(position.begin(), position.end());

        stack<int> result;
        for (int i = 0; i < position.size(); i++) {
            while (!result.empty() && arrivals[position[i]] >= arrivals[result.top()]) {
                result.pop();
            }
            result.push(position[i]);
        }
        return result.size();
    }
};