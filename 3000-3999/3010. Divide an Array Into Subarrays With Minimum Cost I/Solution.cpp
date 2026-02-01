/**
 * Author: Fbin
 * Link:https://leetcode.com/problems/divide-an-array-into-subarrays-with-minimum-cost-i/description/?envType=daily-question&envId=2026-02-01
 * Created at: 01/02/2026
 */

#include <fbin/leetcode.h>

class Solution {
 public:
  int minimumCost(vector<int>& nums) {
    int min1st = INT_MAX, min2nd = INT_MAX;
    for (int i = 1; i < nums.size(); i++) {
      if (nums[i] <= min1st) {
        min2nd = min1st;
        min1st = nums[i];
      } else if (nums[i] < min2nd) {
        min2nd = nums[i];
      }
    }

    return nums[0] + min1st + min2nd;
  }
};
