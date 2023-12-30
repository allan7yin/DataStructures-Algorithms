#include <vector>

using namespace std;

class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> result;
        for (int i = 0; i < asteroids.size(); i++) {
            result.push_back(asteroids[i]);
            while (result.size() >= 2 && result[result.size()-1] < 0 && result[result.size()-2] > 0) {
                int n1 = result.back();
                result.pop_back();
                int n2 = result.back();
                result.pop_back(); 

                if (abs(n1) > n2) {
                    result.push_back(n1);
                } else if (abs(n1) < n2) {
                    result.push_back(n2);
                }
            }
        }
        return result;
    }
};

int main () {}