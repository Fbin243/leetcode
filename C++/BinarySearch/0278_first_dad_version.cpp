/**
 * Author: Fbin
 * Link:https://leetcode.com/problems/first-bad-version/description/?envType=problem-list-v2&envId=binary-search
 * Created at: 07/04/2025
 */

#include <bits/stdc++.h>

using namespace std;

// The API isBadVersion is defined for you.
bool isBadVersion(int version);

class Solution {
 public:
  int firstBadVersion(int n) {
    int l = 0;
    int r = n - 1;
    while (l <= r) {
      int m = l + (r - l) / 2;
      if (isBadVersion(m)) {
        r = m - 1;
      } else {
        l = m + 1;
      }
    }
    
    return l;
  }
};