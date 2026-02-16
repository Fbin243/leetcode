/**
 * Author: Fbin
 * Link:https://leetcode.com/problems/reverse-bits/description/?envType=daily-question&envId=2026-02-16
 * Created at: 16/02/2026
 */

#include <fbin/leetcode.h>

class Solution {
 public:
  int reverseBits(int n) {
    int res = 0;
    for (int i = 31; i >= 0; i--) {
      res += pow(2, i) * (n & 1);
      n = n >> 1;
    }

    return res;
  }
};
