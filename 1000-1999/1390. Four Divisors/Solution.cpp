/**
 * Author: Fbin
 * Link:https://leetcode.com/problems/four-divisors/description/?envType=daily-question&envId=2026-01-04
 * Created at: 04/01/2026
 */

#include <fbin/leetcode.h>

class Solution {
 public:
  int sumOfDivisors(int a) {
    int count = 0;
    int sum = 1 + a;
    for (int i = 2; i <= sqrt(a); i++) {
      if (count > 2) return 0;
      if (a % i == 0) {
        count++;
        sum += i;
        if (a / i != i) {
          count++;
          sum += a / i;
        }
      }
    }

    return count == 2 ? sum : 0;
  }

  int sumFourDivisors(vector<int>& nums) {
    int sum = 0;
    for (int i = 0; i < nums.size(); i++) {
      sum += sumOfDivisors(nums[i]);
    }

    return sum;
  }
};
