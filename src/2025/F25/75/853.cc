#include "../bits/stdc++.h"
using namespace std;

class Solution {
  public:
    int carFleet(int target, vector<int> &position, vector<int> &speed) {
        vector<double> times;
        vector<pair<double, double>> cars;
        for (int i = 0; i < position.size(); i++) {
            cars.push_back({(double)position[i], (double)speed[i]});
        }

        sort(cars.begin(), cars.end(), [](auto &a, auto &b) {
            return a.first < b.first;
        });

        for (int i = 0; i < cars.size(); i++) {
            auto [pos, sp] = cars[i];
            double time = (target - pos) / sp;

            while (!times.empty() && time >= times.back()) {
                times.pop_back();
            }
            times.push_back(time);
        }

        return times.size();
    }
};