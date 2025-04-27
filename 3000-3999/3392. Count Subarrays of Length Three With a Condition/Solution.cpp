/**
 * Author: Fbin
 * Link:https://leetcode.com/problems/count-subarrays-of-length-three-with-a-condition/?envType=daily-question&envId=2025-04-27
 * Created at: 27/04/2025
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  int countSubarrays(vector<int>& nums) {
    int res = 0;
    for (int i = 2; i < nums.size(); i++) {
      if ((nums[i] + nums[i - 2]) * 2 == nums[i - 1]) res++;
    }

    return res;
  }
};
