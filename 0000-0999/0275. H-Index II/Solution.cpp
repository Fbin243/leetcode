/**
 * Author: Fbin
 * Link:https://leetcode.com/problems/missing-number/description/?envType=problem-list-v2&envId=binary-search
 * Created at: 07/04/2025
 */

#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  int hIndex(vector<int>& citations) {
    int n = citations.size();
    int l = 0;
    int r = n - 1;
    while (l <= r) {
      int m = l + (r - l) / 2;
      if (n - m <= citations[m]) {
        r = m - 1;
      } else {
        l = m + 1;
      }
    }

    return n - l;
  }
};