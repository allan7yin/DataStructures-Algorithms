#include "../bits/stdc++.h"
using namespace std;

class Solution {
  public:
    vector<int> dailyTemperatures(vector<int> &temperatures) {
        vector<int> st;
        vector<int> result(temperatures.size(), 0);

        for (int i = 0; i < temperatures.size(); i++) {
            int temp = temperatures[i];
            while (!st.empty() && temp > temperatures[st.back()]) {
                result[st.back()] = i - st.back();
                st.pop_back();
            }
            st.push_back(i);
        }

        return result;
    }
};