#include <vector>
#include <queue>
using namespace std;

class Solution
{
public:
  int numSubarraysWithSum(vector<int> &nums, int goal)
  {
    // we solve this with a sliding window
    int count = 0;
    int l = 0;
    int sum = 0;
    int tail = 0;

    for (int r = 0; r < nums.size(); r++)
    {
      sum += nums[r];
      if (nums[r] == 1)
      {
        tail = 0;
      }

      while (l <= r && sum >= goal)
      {
        if (sum == goal)
        {
          tail++;
        }
        sum -= nums[l];
        l++;
      }
      count += tail;
    }
    return count;
  }
};