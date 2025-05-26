/**
 * Author: Fbin
 * Link:https://leetcode.com/problems/car-fleet/description/
 * Created at: 25/05/2025
 */

#include <bits/stdc++.h>
using namespace std;

/**
 * Fbin's solution
 * Approach: Sorting + Monotonic Stack
 * Time: O(nlogn)
 * Space: O(n)
 */
class Solution {
 public:
  bool isSlower(const pair<int, int>& car1, const pair<int, int>& car2,
                int target) {
    double t1 = (target - car1.first) * 1.0 / car1.second;
    double t2 = (target - car2.first) * 1.0 / car2.second;
    return t1 >= t2;
  }

  int carFleet(int target, vector<int>& position, vector<int>& speed) {
    vector<pair<int, int>> cars;
    stack<pair<int, int>> st;
    for (int i = 0; i < position.size(); i++) {
      cars.push_back({position[i], speed[i]});
    }

    sort(cars.begin(), cars.end());

    for (pair<int, int> car : cars) {
      while (!st.empty() && isSlower(car, st.top(), target)) {
        st.pop();
      }

      st.push(car);
    }

    return st.size();
  }
};