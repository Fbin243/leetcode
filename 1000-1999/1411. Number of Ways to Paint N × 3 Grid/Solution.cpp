/**
 * Author: Fbin
 * Link:https://leetcode.com/problems/number-of-ways-to-paint-n-3-grid/description/\?envType\=daily-question\&envId\=2026-01-03
 * Created at: 03/01/2026
 */

#include <fbin/leetcode.h>

class Solution {
 public:
  long modulo(long n) { return n % static_cast<long>(pow(10, 9) + 7); }

  int numOfWays(int n) {
    long a1 = 6, b1 = 6;
    long a2 = 6, b2 = 6;
    for (int i = 1; i < n; i++) {
      a2 = 3 * a1 + 2 * b1;
      b2 = 2 * a1 + 2 * b1;
      a1 = modulo(a2);
      b1 = modulo(b2);
    }
    return modulo(a2 + b2);
  }
};
