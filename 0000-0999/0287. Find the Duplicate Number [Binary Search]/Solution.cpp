/**
 * Author: Fbin
 * Link:https://leetcode.com/problems/find-the-duplicate-number/description/?envType=problem-list-v2&envId=binary-search
 * Created at: 07/04/2025
 */

#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  /**
   * Time: O(n)
   * Space: O(1)
   * Idea: Use the negative sign to mark the visited numbers.
   */
  int findDuplicate(vector<int>& nums) {
    for (int i = 0; i < nums.size(); i++) {
      int abs_num = abs(nums[i]);
      if (nums[abs_num] < 0) return abs_num;
      nums[abs_num] *= -1;
    }

    return -1;
  }

  /**
   * Time: O(nlogn)
   * Space: O(1)
   * Idea: Binary search.
   */
  int findDuplicate(vector<int>& nums) {
    int l = 1;
    int r = nums.size() - 1;
    while (l < r) {
      int m = l + (r - l) / 2;
      int count = 0;
      for (int i = 0; i < nums.size(); i++) {
        if (nums[i] <= m) count++;
      }
      if (count > m) {
        r = m;
      } else {
        l = m + 1;
      }
    }

    return l;
  }

  /**
   * Time: O(n)
   * Space: O(1)
   * Idea: Floyd's Tortoise and Hare (Cycle Detection).
   */
  int findDuplicate(vector<int>& nums) {
    int slow = nums[0];
    int fast = nums[0];

    do {
      slow = nums[slow];
      fast = nums[nums[fast]];
    } while (slow != fast);

    fast = nums[0];
    while (slow != fast) {
      slow = nums[slow];
      fast = nums[fast];
    }

    return slow;
  }
};
