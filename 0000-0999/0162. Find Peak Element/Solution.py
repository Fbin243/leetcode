'''/**
 * Author: Fbin
 * Link:https://leetcode.com/problems/find-peak-element/?envType=problem-list-v2&envId=binary-search
 * Created at: 05/04/2025
 */
'''
class Solution:
  def findPeakElement(self, nums: list[int]) -> int:
    l = 0
    r = len(nums) - 1
    while l < r:
      m = (l + r) // 2
      if nums[m] > nums[m + 1]:
        r = m
      else:
        l = m + 1
    return l