/**
 * Author: Fbin
 * Link:https://leetcode.com/problems/find-minimum-in-rotated-sorted-array-ii/description/?envType=problem-list-v2&envId=binary-search
 * Created at: 05/04/2025
 */

#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  int findMin(vector<int>& nums) {
    int l = 0;
    int r = nums.size() - 1;
    while (l < r) {
      int m = l + (r - l) / 2;
      if (nums[m] > nums[r])
        l = m + 1;
      else if (nums[m] < nums[r])
        r = m;
      else
        r--;
    }

    return nums[l];
  }
};