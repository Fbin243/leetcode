/**
 * Author: Fbin
 * Link:https://leetcode.com/problems/count-covered-buildings/description/
 * Created at: 27/04/2025
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  /**
   * Approach: Brute force (TLE - pass 619/634)
   * Time complexity: O(n^2)
   * Space complexity: O(1)
   */
  int countCoveredBuildings(int n, vector<vector<int>>& buildings) {
    int res = 0;
    for (auto& b1 : buildings) {
      bool hasLeft = false, hasRight = false, hasTop = false, hasBottom = false;
      for (auto& b2 : buildings) {
        if (b2[1] == b1[1]) {
          if (b2[0] < b1[0]) hasLeft = true;
          if (b2[0] > b1[0]) hasRight = true;
        }

        if (b2[0] == b1[0]) {
          if (b2[1] < b1[1]) hasBottom = true;
          if (b2[1] > b1[1]) hasTop = true;
        }
      }
      if (hasLeft && hasRight && hasTop && hasBottom) res++;
    }

    return res;
  }

  /**
   * Approach: Fbin's solution
   * Time Complexity: O(nlogn)
   * Space Complexity: O(n)
   */
  int countCoveredBuildings(int n, vector<vector<int>>& buildings) {
    unordered_map<int, vector<int>> xm;
    unordered_map<int, vector<int>> ym;
    // sort(buildings.begin(), buildings.end(), compareVector); (TLE - pass
    // 625/634)
    sort(buildings.begin(), buildings.end());
    int res = 0;

    for (int i = 0; i < buildings.size(); i++) {
      xm[buildings[i][0]].push_back(buildings[i][1]);
      ym[buildings[i][1]].push_back(buildings[i][0]);

      vector<int>& xv = ym[buildings[i][1]];
      if (xv.size() >= 3) {
        int key = xv[xv.size() - 2];
        vector<int>& xv = xm[key];
        int found =
            lower_bound(xv.begin(), xv.end(), buildings[i][1]) - xv.begin();
        if (found > 0 && found < xv.size() - 1) {
          res++;
        }
      }
    }

    return res;
  }

  static bool compareVector(vector<int> a, vector<int> b) {
    if (a[0] < b[0]) return true;
    if (a[0] > b[0]) return false;
    return a[1] < b[1];
  }

  /**
   * Approach: Set and Map with equal_range (binary search)
   * Time Complexity: O(nlogn)
   * Space Complexity: O(n)
   */
  int countCoveredBuildings(int n, vector<vector<int>>& buildings) {
    unordered_map<int, set<int>> xm, ym;
    int res = 0;

    for (auto& b : buildings) {
      xm[b[0]].insert(b[1]);
      ym[b[1]].insert(b[0]);
    }

    for (auto& b : buildings) {
      int x = b[0];
      int y = b[1];
      auto [left, right] = xm[x].equal_range(y);
      auto [bottom, top] = ym[y].equal_range(x);

      bool hasLeft = left != xm[x].begin();
      bool hasRight = right != xm[x].end();
      bool hasTop = top != ym[y].end();
      bool hasBottom = bottom != ym[y].begin();

      if (hasLeft && hasRight && hasTop && hasBottom) res++;
    }

    return res;
  }

  /**
   * Approach: vector with lower_bound and upper_bouud (binary search)
   * Time Complexity: O(nlogn)
   * Space Complexity: O(n)
   */
  int countCoveredBuildings(int n, vector<vector<int>>& buildings) {
    unordered_map<int, vector<int>> xm, ym;
    int res = 0;

    for (auto& b : buildings) {
      xm[b[0]].push_back(b[1]);
      ym[b[1]].push_back(b[0]);
    }

    for (auto& [_, v] : xm) sort(v.begin(), v.end());
    for (auto& [_, v] : ym) sort(v.begin(), v.end());

    for (auto& b : buildings) {
      auto& yv = xm[b[0]];
      auto& xv = ym[b[1]];

      bool hasLeft = lower_bound(xv.begin(), xv.end(), b[0]) != xv.begin();
      bool hasRight = upper_bound(xv.begin(), xv.end(), b[0]) != xv.end();
      bool hasBottom = lower_bound(yv.begin(), yv.end(), b[1]) != yv.begin();
      bool hasTop = upper_bound(yv.begin(), yv.end(), b[1]) != yv.end();

      if (hasLeft && hasRight && hasTop && hasBottom) res++;
    }

    return res;
  }
};
