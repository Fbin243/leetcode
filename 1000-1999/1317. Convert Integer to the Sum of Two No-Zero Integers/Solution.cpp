/**
 * Author: Fbin
 * Link:https://leetcode.com/problems/convert-integer-to-the-sum-of-two-no-zero-integers/description/?envType=daily-question&envId=2025-09-08
 * Created at: 08/09/2025
 */

#include <fbin/leetcode.h>
using namespace std;

class Solution {
 public:
  bool includeZero(int n) {
    while (n > 0) {
      if (n % 10 == 0) return true;
      n /= 10;
    }
    return false;
  }
  vector<int> getNoZeroIntegers(int n) {
    for (int i = 1; i <= n / 2; i++) {
      if (!includeZero(i) && !includeZero(n - i)) return vector<int>{i, n - i};
    }
    return vector<int>{};
  }
};
