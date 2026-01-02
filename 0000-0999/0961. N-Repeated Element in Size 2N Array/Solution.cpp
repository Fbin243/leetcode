/**
 * Author: Fbin
 * Link:https://leetcode.com/problems/n-repeated-element-in-size-2n-array/\?envType\=daily-question\&envId\=2026-01-03
 * Created at: 03/01/2026
 */

#include <fbin/leetcode.h>

class Solution {
 public:
  // Counter
  int repeatedNTimes(vector<int>& nums) {
    unordered_set<int> s;
    for (int i = 0; i < nums.size(); i++) {
      if (s.find(nums[i]) != s.end()) return nums[i];
      s.insert(nums[i]);
    }

    return -1;
  }

  // Compare
  int repeatedNTimes(vector<int>& nums) {
    for (int i = 0; i < nums.size(); i++) {
      for (int k = i + 1; k <= i + 3; k++) {
        if (k < nums.size() && nums[i] == nums[k]) return nums[i];
      }
    }

    return -1;
  }
};
