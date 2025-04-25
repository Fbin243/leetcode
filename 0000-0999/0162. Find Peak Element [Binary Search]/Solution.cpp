/**
 * Author: Fbin
 * Link:https://leetcode.com/problems/find-peak-element/?envType=problem-list-v2&envId=binary-search
 * Created at: 05/04/2025
 */

#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  int findPeakElement(vector<int>& nums) {
    int l = 0;
    int n = nums.size();
    int r = n - 1;
    while (l <= r) {
      int m = l + (r - l) / 2;
      int ml = m > 0 ? nums[m - 1] : INT_MIN;
      int mr = m < n - 1 ? nums[m + 1] : INT_MIN;
      if (nums[m] > ml && nums[m] > mr) {
        return m;
      }
      if (nums[m] >= ml) {
        l = m + 1;
      } else {
        r = m - 1;
      }
    }

    return 0;
  }

  int findPeakElement(vector<int>& nums) {
    int l = 0;
    int r = nums.size() - 1;
    while (l < r) {
      int m = l + (r - l) / 2;
      if (nums[m] > nums[m + 1]) {
        r = m;
      } else {
        l = m + 1;
      }
    }

    return l;
  }
};