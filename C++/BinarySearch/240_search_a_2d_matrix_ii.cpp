/**
 * Author: Fbin
 * Link:https://leetcode.com/problems/search-a-2d-matrix-ii/?envType=problem-list-v2&envId=binary-search
 * Created at: 05/04/2025
 */

#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  /**
   * Time: O(m * log(n))
   * Space: O(1)
   * Approach: Binary Search
   * 1. For each row, we can use binary search to find the target.
   * 2. We can use lower_bound to find the first element that is greater than or
   * equal to the target.
   */
  bool searchMatrix(vector<vector<int>>& matrix, int target) {
    for (int i = 0; i < matrix.size(); i++) {
      int j = lower_bound(matrix[i].begin(), matrix[i].end(), target) -
              matrix[i].begin();
      if (j < matrix[i].size() && matrix[i][j] == target) return true;
    }

    return false;
  }

  /**
   * Time: O(m + n)
   * Space: O(1)
   * Approach: Two Pointers
   * 1. Start from the top-right corner of the matrix.
   * 2. If the current element is equal to the target, return true.
   * 3. If the current element is greater than the target, move left.
   * 4. If the current element is less than the target, move down.
   */
 public:
  bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int i = 0;
    int j = matrix[0].size() - 1;
    while (i < matrix.size() && j >= 0) {
      if (matrix[i][j] == target)
        return true;
      else if (matrix[i][j] < target)
        j--;
      else
        i++;
    }

    return false;
  }

  /**
   * Time: O(m * n)
   * Space: O(1)
   * Approach: Brute Force
   * 1. Iterate through the matrix and check if the current element is equal to
   * the target.
   */
 public:
  bool searchMatrix(vector<vector<int>>& matrix, int target) {
    for (int i = 0; i < matrix.size(); i++) {
      for (int j = 0; j < matrix[i].size(); j++) {
        if (matrix[i][j] == target) return true;
      }
    }

    return false;
  }
};