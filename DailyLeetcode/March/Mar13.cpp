class Solution
{
public:
  int pivotInteger(int n)
  {
    // calculate sum of integers
    long val = n * (n + 1) / 2;
    int result = -1;
    int count = 0;
    for (int i = 1; i <= n; i++)
    {
      count += i;
      if (count == val - count + i)
      {
        result = i;
        break;
      }
    }
    return result;
  }
};