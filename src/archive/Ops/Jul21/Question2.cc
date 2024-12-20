#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

struct ProcessSchedule {
  int startTime;
  int endTime;
};

struct Dependency {
  int pid1;
  int pid2;
};

class Scheduler {
public:
  // Remember, to do a topological sort, or rather cycle detection, we need only
  // // to compute a DFS when we're not in a LL setting
  void dfs(int u, vector<int> colour) {
    colour[u] = 1;
    for (auto &n : startG[u]) {
      if (colour[n] == 1) {
        cycle = true;
        return;
      } else if (colour[n] == 0) {
        dfs(n, colour);
      }
    }
    colour[u] = 2;
  }

  // processes is an array of start and end time pairs for the ith task
  // the start time is the earliest time and the end time is the latest end time
  Scheduler(const std::vector<ProcessSchedule> &processes,
            const std::vector<Dependency> &dependencies) {
    // instantiate our graph
    int n = processes.size();
    startG.resize(n + 1);
    reverseG.resize(n + 1);

    for (auto &val : dependencies) {
      startG[val.pid1].push_back(val.pid2);
      reverseG[val.pid2].push_back(val.pid1);
    }

    // run topo sort on this
    vector<int> colour(n + 1, 0);
    dfs(1, colour);

    // now, try and assign start and end times for each of the processes
    for (int i = 1; i < n + 1; i++) {
      int start = processes[i - 1].startTime, end = processes[i - 1].endTime;

      for (auto &v : reverseG[i]) {
        // this conditions is necessary in cases where a dependency ends after
        // we can even start we can only run current process while dependency is
        // running, so impossible, so just make cycle = true
        if (processes[i - 1].startTime >= processes[v - 1].endTime - 1) {
          // cycle not actually true, but setting this flag to say schedule is
          // impossible
          cycle = true;
        }
        start = max(start, processes[v - 1].startTime);
        end = min(end, processes[v - 1].endTime);
      }

      if (reverseG[i].size()) {
        start++;
        end--;
      }

      result.push_back({start, end});
    }
  }

  // use std::cout for output stream
  void PrintSchedule() {
    if (cycle) {
      cout << "IMPOSSIBLE" << endl;
    }
    cout << result.size() << endl;
    for (int i = 0; i < result.size(); i++) {
      cout << i + 1 << ": start = " << result[i].startTime
           << ", end  = " << result[i].endTime << endl;
    }
  }

private:
  vector<vector<int>> startG;
  vector<vector<int>> reverseG;
  vector<ProcessSchedule> result;
  bool cycle = false;
};

int main() {
  // Test data
  // test 0
  vector<ProcessSchedule> processes = {{100, 2100}, {110, 2200}, {200, 2330}};
  vector<Dependency> dependencies = {{1, 2}, {3, 2}};

  // test 1
  vector<ProcessSchedule> processes1 = {{900, 1800}, {1799, 2400}};
  vector<Dependency> dependencies1 = {{1, 2}};

  // test 2
  vector<ProcessSchedule> processes2 = {{100, 10000}, {100, 10000}};
  vector<Dependency> dependencies2 = {{1, 2}, {2, 1}};

  // Create Scheduler
  cout << "Test 0" << endl;
  cout << "=============" << endl;
  Scheduler scheduler(processes, dependencies);
  // Print the schedule
  scheduler.PrintSchedule();

  cout << "Test 1" << endl;
  cout << "=============" << endl;
  Scheduler scheduler1(processes1, dependencies1);
  // Print the schedule
  scheduler1.PrintSchedule();

  cout << "Test 2" << endl;
  cout << "=============" << endl;
  Scheduler scheduler2(processes2, dependencies2);
  // Print the schedule
  scheduler2.PrintSchedule();

  return 0;
}
