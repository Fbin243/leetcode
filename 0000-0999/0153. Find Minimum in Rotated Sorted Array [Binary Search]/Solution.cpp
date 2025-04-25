/**
 * Author: Fbin
 * Link:https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/description/?envType=problem-list-v2&envId=binary-search
 * Created at: 05/04/2025
 */
#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  int findMin(vector<int>& nums) {
    int l = 0;
    int r = nums.size() - 1;
    int ans = 5001;
    while (l <= r) {
      int m = l + (r - l) / 2;
      if (nums[m] < ans) ans = nums[m];
      if (nums[l] > nums[r]) {
        if (nums[m] >= nums[l]) {
          l = m + 1;
        } else {
          r = m - 1;
        }
      } else {
        if (nums[m] >= nums[l]) {
          r = m - 1;
        } else {
          l = m + 1;
        }
      }
    }

    return ans;
  }

  int findMin2(vector<int>& nums) {
    int l = 0;
    int r = nums.size() - 1;
    while (l < r) {
      int m = l + (r - l) / 2;
      if (nums[m] > nums[r])
        l = m + 1;
      else
        r = m;
    }

    return nums[l];
  }
};