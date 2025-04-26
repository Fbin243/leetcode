/**
 * Author: Fbin
 * Link:https://leetcode.com/problems/count-subarrays-with-fixed-bounds/?envType=daily-question&envId=2025-04-26
 * Created at: 26/04/2025
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  /**
   * Approach: Brute Force
   * Time Complexity: O(n^2)
   * Space Complexity: O(1)
   * We can use a brute force approach to find all the subarrays and check if
   * they contain the minimum and maximum values. We can do this by iterating
   * through all the subarrays and checking if they contain the minimum and
   * maximum values.
   */
  long long countSubarrays(vector<int>& nums, int minK, int maxK) {
    int res = 0;
    for (int i = 0; i < nums.size(); i++) {
      int minVal = nums[i];
      int maxVal = nums[i];
      for (int j = i; j < nums.size(); j++) {
        if (nums[j] > maxVal) maxVal = nums[j];
        if (nums[j] < minVal) minVal = nums[j];
        if (minVal == minK && maxVal == maxK) res++;
      }
    }

    return res;
  }

  /**
   * Approach: Sliding Window
   * Time Complexity: O(n)
   * Space Complexity: O(1)
   */
  long long countSubarrays(vector<int>& nums, int minK, int maxK) {
    int l = 0, r = 0, minIdx = 0, maxIdx = 0;
    long long res = 0;

    while (r < nums.size()) {
      if (nums[r] < minK || nums[r] > maxK) {
        l = r + 1;
        minIdx = r + 1;
        maxIdx = r + 1;
      } else {
        if (nums[r] <= nums[minIdx]) minIdx = r;
        if (nums[r] >= nums[maxIdx]) maxIdx = r;
        if (nums[minIdx] == minK && nums[maxIdx] == maxK) {
          res += min(minIdx, maxIdx) - l + 1;
        }
      }

      r++;
    }

    return res;
  }
};