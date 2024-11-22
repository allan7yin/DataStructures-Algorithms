#include <vector>
#include <string>

using namespace std;

vector<char> prio(26, 26);

class Solution
{
public:
  string customSortString(string order, string s)
  {
    // construct map
    int count = 0;
    for (int i = 0; i < order.size(); i++)
    {
      int index = order[i] - 'a';
      prio[index] = count;
      count++;
    }

    // now, sort and return
    sort(s.begin(), s.end(), comparator);
    return s;
  }

  static bool comparator(char &c1, char &c2)
  {
    if (prio[c1 - 'a'] < prio[c2 - 'a'])
    {
      return true;
    }
    else
    {
      return false;
    }
  }
};