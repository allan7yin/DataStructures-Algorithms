#include <algorithm>
#include <iostream>
#include <vector>

struct Process {
  int startTime;
  int endTime;
};

Process processes[] = {
    {100, 2100}, // Process 0
    {201, 2099}, // Process 1
    {200, 2330}  // Process 2
};

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

int main() {
  std::vector<int> schedule = {0, 1, 2};
  std::vector<int> startTimes(3, -1); // Initialize with -1

  if (scheduleProcessesMaxInterval(schedule, startTimes)) {
    for (int i = 0; i < startTimes.size(); ++i) {
      std::cout << startTimes[i] << " ";
    }
    std::cout << std::endl;
  } else {
    std::cout << "Scheduling failed." << std::endl;
  }

  return 0;
}
