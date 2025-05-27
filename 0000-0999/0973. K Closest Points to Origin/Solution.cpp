/**
 * Author: Fbin
 * Link:https://leetcode.com/problems/k-closest-points-to-origin/description/
 * Created at: 27/05/2025
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
    auto cmp = [](vector<int> a, vector<int> b) {
      return sqrt(pow(a[0], 2) + pow(a[1], 2)) >
             sqrt(pow(b[0], 2) + pow(b[1], 2));
    };

    priority_queue<vector<int>, vector<vector<int>>, decltype(cmp)> pq = {
        points.begin(), points.end()};

    vector<vector<int>> res;
    while (k--) {
      res.push_back(pq.top());
      pq.pop();
    }

    return res;
  }
};