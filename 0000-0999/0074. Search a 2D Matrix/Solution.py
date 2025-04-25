'''
/**
 * Author: Fbin
 * Link:https://leetcode.com/problems/search-a-2d-matrix/description/?envType=problem-list-v2&envId=binary-search
 * Created at: 31/03/2025
 */
'''

from typing import List


class Solution:
    def searchMatrix(self, matrix: List[List[int]], target: int) -> bool:
        row, col = len(matrix), len(matrix[0]) if matrix else 0
        left, right = 0  , row * col - 1
        while(left <= right): 
            mid = left + (right - left) // 2
            mid_val = matrix[mid // col][mid % col]
            if mid_val == target: return True
            elif mid_val < target: left = mid + 1
            else: right = mid - 1
        return False