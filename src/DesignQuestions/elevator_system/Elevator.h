#include "Person.h"
#include <algorithm>
#include <unordered_map>
#include <vector>

enum State { UP, DOWN, IDLE, STOPPED };

class Elevator {
private:
  double weightLimit;

public:
  int maxLevel;
  int currentLevel = 0;
  int remainingFloors = 0;
  State status;
  std::unordered_map<int, std::vector<Person *>> upLevels;
  std::unordered_map<int, std::vector<Person *>> downLevels;

  Elevator(double weightLimit, int maxLevel, State status) {
    this->weightLimit = weightLimit;
    this->maxLevel = maxLevel;
    this->status = status;

    upLevels = std::unordered_map<int, std::vector<Person *>>();
    downLevels = std::unordered_map<int, std::vector<Person *>>();
  }
};
