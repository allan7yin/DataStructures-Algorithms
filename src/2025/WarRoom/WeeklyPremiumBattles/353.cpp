#include "../bits/stdc++.h"
using namespace std;

class SnakeGame {
    deque<pair<int, int>> body;
    set<pair<int, int>> seen;
    vector<vector<int>> food;
    int food_index = 0;
    int width;
    int height;

  public:
    SnakeGame(int width, int height, vector<vector<int>> &food)
        : width(width), height(height), food(food) {
        // Initialize snake at (0,0)
        body.push_back({0, 0});
        seen.insert({0, 0});
    }

    int move(string direction) {
        // Get current head position
        int r = body.front().first;
        int c = body.front().second;

        // Calculate new head position
        if (direction == "U") {
            r--;
        } else if (direction == "D") {
            r++;
        } else if (direction == "L") {
            c--;
        } else { // "R"
            c++;
        }

        // Check bounds - FIXED: r checks height, c checks width
        if (r < 0 || r >= height || c < 0 || c >= width) {
            return -1;
        }

        // Check if eating food
        bool eating_food = false;
        if (food_index < food.size()) {
            int food_r = food[food_index][0];
            int food_c = food[food_index][1];
            if (r == food_r && c == food_c) {
                eating_food = true;
                food_index++;
            }
        }

        // If NOT eating food, remove tail first (to avoid false self-collision)
        if (!eating_food) {
            pair<int, int> tail = body.back();
            body.pop_back();
            seen.erase(tail);
        }

        // Check self-collision AFTER potentially removing tail
        if (seen.find({r, c}) != seen.end()) {
            return -1;
        }

        // Add new head
        body.push_front({r, c});
        seen.insert({r, c});

        // Return score (length - 1)
        return body.size() - 1;
    }
};