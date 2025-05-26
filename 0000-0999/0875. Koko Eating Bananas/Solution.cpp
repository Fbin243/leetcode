/**
 * Author: Fbin
 * Link:https://leetcode.com/problems/koko-eating-bananas/description/
 * Created at: 26/05/2025
 */

#include <bits/stdc++.h>
using namespace std;

/**
 * Fbin's solution: 7ms
 * Time: O(logm * n) m - the max value of bananas in piles, n - the pile's
 * length. \\ ---- m <= 10e4, n <= 10e9
 * Space: O(1)
 */
class Solution {
 public:
  long evalHour(vector<int>& piles, int speed) {
    long hour = 0;
    for (int i = 0; i < piles.size(); i++) {
      hour += ceil(piles[i] * 1.0 / speed);
    }

    return hour;
  }

  int minEatingSpeed(vector<int>& piles, int h) {
    int r = 0;
    for (int i = 0; i < piles.size(); i++) {
      r = max(r, piles[i]);
    }

    int l = 1, res = 0;
    while (l <= r) {
      int m = l + (r - l) / 2;
      if (evalHour(piles, m) <= h) {
        res = m;
        r = m - 1;
      } else
        l = m + 1;
    }

    return res;
  }
};