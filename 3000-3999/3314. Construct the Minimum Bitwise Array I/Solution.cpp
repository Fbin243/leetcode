/**
 * Author: Fbin
 * Link:https://leetcode.com/problems/construct-the-minimum-bitwise-array-i/?envType=daily-question&envId=2026-01-31
 * Created at: 31/01/2026
 */

#include <fbin/leetcode.h>

class Solution {
 public:
  int findAns(int a) {
    for (int i = 0; i < 1000; i++) {
      if ((i | (i + 1)) == a) return i;
    }

    return -1;
  }

  vector<int> minBitwiseArray(vector<int>& nums) {
    for (int i = 0; i < nums.size(); i++) {
      nums[i] = findAns(nums[i]);
    }

    return nums;
  }
};
