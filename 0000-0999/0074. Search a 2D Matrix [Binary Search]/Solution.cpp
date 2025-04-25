/**
 * Author: Fbin
 * Link:https://leetcode.com/problems/search-a-2d-matrix/?envType=problem-list-v2&envId=binary-search
 * Created at: 31/03/2025
 */
#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int row = matrix.size();
    int col = matrix[0].size();
    int l = 0;
    int r = row * col - 1;

    while (l <= r) {
      int m = l + (r - l) / 2;
      int value = matrix[m / col][m % col];
      if (value == target) return true;
      if (value < target) {
        l = m + 1;
      } else {
        r = m - 1;
      }
    }
    return false;
  }
};