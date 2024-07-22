#include <algorithm>
#include <bitset>
#include <climits>
#include <cmath>
#include <cstdint>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <iostream>
#include <limits>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <vector>

struct ProcessSchedule {
  int startTime;
  int endTime;
};

struct Dependency {
  int pid1;
  int pid2;
};

class Graph {
public:
  int vertices;
  int n;
  std::vector<std::vector<int>> adjMatrix;
  // constructor
  Graph(int vertices) : vertices(vertices) {
    adjMatrix.resize(vertices);
    this->n = vertices;
  }

  // add directed arc uv
  void addEdge(int u, int v) { adjMatrix[u].push_back(v); }

  // apply topological sort
  bool topologicalSort(std::vector<int> &schedule) {
    std::vector<bool> visited(vertices, false);
    std::stack<int> st;

    for (int i = 0; i < vertices; ++i) {
      if (!visited[i]) {
        dfs(i, visited, st);
      }
    }

    while (!st.empty()) {
      schedule.push_back(st.top());
      st.pop();
    }

    return schedule.size() == n;
  }

  // dfs
  void dfs(int v, std::vector<bool> &visited, std::stack<int> &st) {
    visited[v] = true;

    for (int i : adjMatrix[v]) {
      if (!visited[i]) {
        dfs(i, visited, st);
      }
    }

    st.push(v);
  }
};

class Scheduler {
public:
  Scheduler(const std::vector<ProcessSchedule> &processes,
            const std::vector<Dependency> &dependencies) {
    this->processes = processes;
    int n = processes.size();
    g = new Graph(n);
    // add arcs
    for (auto &d : dependencies) {
      g->addEdge(d.pid1, d.pid2);
    }
  }

  bool scheduleProcessesMaxInterval(const std::vector<int> &schedule,
                                    std::vector<int> &startTimes) {
    int n = schedule.size();
    std::vector<int> earliestStart(n, 0);

    // Forward pass: Calculate the earliest start time for each process
    for (int i = 0; i < n; ++i) {
      int pid = schedule[i];
      int start = processes[pid].startTime;
      int end = processes[pid].endTime;

      if (start > end)
        return false; // Invalid time window

      if (i == 0) {
        earliestStart[pid] = start;
      } else {
        int prevPid = schedule[i - 1];
        earliestStart[pid] = std::max(start, earliestStart[prevPid] + 1);
      }

      if (earliestStart[pid] > end)
        return false; // Cannot fit within the window
    }

    // Backward pass: Adjust the start times to maximize the intervals
    for (int i = n - 1; i >= 0; --i) {
      int pid = schedule[i];
      int end = processes[pid].endTime;

      if (i == n - 1) {
        startTimes[pid] = end;
      } else {
        int nextPid = schedule[i + 1];
        startTimes[pid] = std::min(end, startTimes[nextPid] - 1);
      }

      startTimes[pid] = std::max(startTimes[pid], processes[pid].startTime);
    }

    return true;
  }

  // use std::cout for output stream
  void PrintSchedule() {
    std::vector<int> schedule;
    if (!g->topologicalSort(schedule)) {
      std::cout << "IMPOSSIBLE" << std::endl;
      return;
    }

    std::vector<int> startTimes(processes.size(), -1);
    if (!scheduleProcessesMaxInterval(schedule, startTimes)) {
      std::cout << "IMPOSSIBLE" << std::endl;
      return;
    }

    for (int i = 0; i < processes.size(); i++) {
      std::cout << startTimes[i] << " " << startTimes[i] + 1 << std::endl;
    }
  }

  ~Scheduler() { delete g; }

private:
  Graph *g;
  std::vector<ProcessSchedule> processes;
  std::vector<int> sortedProcesses;
  std::unordered_map<int, int> maxTimes;
};

int main() {
  std::vector<ProcessSchedule> processes = {
      {100, 2100}, {110, 2200}, {200, 2330}};
  std::vector<Dependency> dependencies = {{1, 2}, {3, 2}};

  Scheduler scheduler(processes, dependencies);
  scheduler.PrintSchedule();

  return 0;
}
