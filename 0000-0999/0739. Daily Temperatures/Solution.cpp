/**
 * Author: Fbin
 * Link:https://leetcode.com/problems/daily-temperatures/description/
 * Created at: 25/05/2025
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  vector<int> dailyTemperatures(vector<int>& temperatures) {
    stack<int> st;
    vector<int> res(temperatures.size(), 0);
    for (int i = 0; i < temperatures.size(); i++) {
      while (!st.empty() && temperatures[st.top()] < temperatures[i]) {
        res[st.top()] = i - st.top();
        st.pop();
      }

      st.push(i);
    }

    return res;
  }
};