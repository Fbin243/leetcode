/**
 * Author: Fbin
 * Link:https://leetcode.com/problems/longest-increasing-subsequence/description/?envType=problem-list-v2&envId=binary-search
 * Created at: 12/04/2025
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  /**
   * Time: O(nlogn)
   * Space: O(n)
   * Idea: Patience sorting.
   * Ref:https://www.cs.princeton.edu/courses/archive/spring13/cos423/lectures/LongestIncreasingSubsequence.pdf
   */
  int lengthOfLIS(vector<int>& nums) {
    vector<int> piles;
    for (int i = 0; i < nums.size(); i++) {
      int pos =
          lower_bound(piles.begin(), piles.end(), nums[i]) - piles.begin();
      if (pos == piles.size()) {
        piles.push_back(nums[i]);
      } else {
        piles[pos] = nums[i];
      }
    }

    return piles.size();
  }
};