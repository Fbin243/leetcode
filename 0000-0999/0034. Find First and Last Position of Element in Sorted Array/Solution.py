'''
/**
 * Author: Fbin
 * Link:https://leetcode.com/problems/sqrtx/description/?envType=problem-list-v2&envId=binary-search
 * Created at: 30/03/2025
 */
'''

from bisect import bisect_left, bisect_right


class Solution:
    def searchRange(self, nums: list[int], target: int) -> list[int]:
        l = bisect_left(nums, target)
        r = bisect_right(nums, target) - 1
        if l <= r:
            return [l, r]
        return [-1, -1]