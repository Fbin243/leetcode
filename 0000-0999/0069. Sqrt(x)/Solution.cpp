/**
 * Author: Fbin
 * Link:https://leetcode.com/problems/sqrtx/description/?envType=problem-list-v2&envId=binary-search
 * Created at: 30/03/2025
 */
#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  int mySqrt(int x) {
    int n = 46341;
    for (int i = 0; i <= n; i++) {
      if (i * i == x) return i;
      if (i * i > x) return i - 1;
    }

    return -1;
  }

  int mySqrt1(int x) {
    int n = 46340;
    int l = 0;
    int r = n;
    while (l <= r) {
      int m = l + (r - l) / 2;
      if (m * m == x) return m;
      if (m * m < x)
        l = m + 1;
      else
        r = m - 1;
    }

    return r;
  }

  float mySqrt2(int x) {
    float n = 46340.95;
    float l = 0;
    float r = n;
    float EPSILON = 1e-5;
    while (r - l > EPSILON) {
      float m = l + (r - l) / 2;
      if (m * m == x) return m;
      if (m * m < x)
        l = m;
      else
        r = m;
    }

    return r;
  }
};

int main() {
  Solution* sol = new Solution();
  int x = 8;
  cout << sol->mySqrt(x) << endl;
  cout << sol->mySqrt2(x);

  return 0;
}
