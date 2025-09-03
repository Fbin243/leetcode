/**
 * Author: Fbin
 * Link:https://leetcode.com/problems/find-the-number-of-ways-to-place-people-ii/description/?envType=daily-question&envId=2025-09-03
 * Created at: 03/09/2025
 */

#include <iostream>
#include <ranges>
#include <vector>
using namespace std;

// this C++ uses ranges::sort with elapsed time 76ms
class Solution {
 public:
  static bool cmp(const vector<int>& p, const vector<int>& q) {
    return (p[0] == q[0]) ? p[1] < q[1] : p[0] > q[0];  // order by (x, >)
  }
  static int numberOfPairs(vector<vector<int>>& P) {
    std::sort(P.begin(), P.end(), cmp);
    int n = P.size(), ans = 0;
    for (int i = 0; i < n - 1; i++) {
      int y = INT_MAX, yi = P[i][1];
      for (int j = i + 1; j < n; j++) {
        const int yj = P[j][1];
        if (yj >= yi && y > yj) {  // P[j] cannot be in between
          ans++;
          y = yj;
          if (yi == yj) break;
        }
      }
    }
    return ans;
  }
};

auto init = []() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  return 'c';
}();
