#include <iostream>
#include <vector>
using namespace std;

/*
There are n cars on x axis. i-th Car's initial position is denoted by position[i] and maximum speed by speed[i].
cars can travel in both directions(left and right). At the end, all cars need to meet at the same location, what would be the minimum time required at which all cars can meet.

Example:

position: [1, 3, 7]
speed: [2, 1, 1]

Answer: 2 (Each car will take 2 units of time if these cars meet at 5.)



How to solve:
- For a given time t, you can compute the range of distances that could be reached by a car.
- So if we have a t, we can compute all ranges for all cars, and see if there is an overlaping area for all cars.
- we can then just binary search for the value of t -> can look into the time complexity of this later
*/

template <typename T>
void print_vector(const vector<T> &res) {
    for (const auto &val : res) {
        cout << val << " ";
    }
    cout << "\n";
}

bool all_overlap(const vector<int> &positions, const vector<int> &speed, int t) {
    // keep track of largest left range index, and smallest right range index
    int max_l = 0, min_r = INT_MAX;
    for (int i = 0; i < positions.size(); i++) {
        int left = positions[i] - speed[i] * t;
        int right = positions[i] + speed[i] * t;
        max_l = max(max_l, left);
        min_r = min(min_r, right);
    }

    return max_l <= min_r;
}

int min_time_to_meet(const vector<int> &positions, const vector<int> &speed) {
    // start with a maximum value of t -> time it woudl take the farthest 2 cars to meet
    int far_left_index = 0, far_right_index = 0;
    for (int i = 0; i < positions.size(); i++) {
        if (positions[i] < positions[far_left_index]) {
            far_left_index = i;
        }
        if (positions[i] > positions[far_right_index]) {
            far_right_index = i;
        }
    }

    int dist = positions[far_right_index] - positions[far_left_index];
    int t = max(dist / speed[far_left_index], dist / speed[far_right_index]);

    int l = 0, r = t;
    int result = t;
    while (l <= r) {
        int m = l + ((r - l) / 2);
        if (all_overlap(positions, speed, m)) {
            result = m;
            r = m - 1;
        } else {
            l = m + 1;
        }
    }

    return result;
}

int main() {
    vector<int> ps = {1, 3, 7};
    vector<int> ss = {2, 1, 1};
    cout << min_time_to_meet(ps, ss);
}

/*
position: [1, 3, 7]
speed: [2, 1, 1]


t = 2 -> Ranges: [-3, 5] [1, 5] [5, 9]


*/
