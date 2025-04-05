/**
 * Author: Fbin
 * Link:https://leetcode.com/problems/search-in-rotated-sorted-array-ii/description/?envType=problem-list-v2&envId=binary-search
 * Created at: 05/04/2025
 */
#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  bool search(vector<int>& nums, int target) {
    int l = 0;
    int r = nums.size() - 1;

    // Remove duplicates to be able to locate the pivot mid and target in two
    // halves
    while (l <= r && nums[l] == nums[r]) {
      if (nums[l] == target) return true;
      l++;
      r--;
    }

    // The same logic with leetcode 33
    // https://leetcode.com/problems/search-in-rotated-sorted-array/description/
    while (l <= r) {
      int mid = l + (r - l) / 2;
      if (nums[mid] == target) return true;
      if (nums[mid] < target) {
        if (nums[mid] < nums[l] && nums[l] <= target) {
          r = mid - 1;
        } else {
          l = mid + 1;
        }
      } else {
        if (target < nums[l] && nums[l] <= nums[mid]) {
          l = mid + 1;
        } else {
          r = mid - 1;
        }
      }
    }

    return false;
  }
};
