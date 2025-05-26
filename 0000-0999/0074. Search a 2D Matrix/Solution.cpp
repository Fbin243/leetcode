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

// Solution at 26/05/2025
class Solution {
 public:
  bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int m = matrix.size();
    int n = matrix[0].size();
    int l = 0, r = (m - 1) * n + (n - 1);
    while (l <= r) {
      int mid = l + (r - l) / 2;
      if (matrix[mid / n][mid % n] == target)
        return true;
      else if (matrix[mid / n][mid % n] < target)
        l = mid + 1;
      else
        r = mid - 1;
    }

    return false;
  }
};

// (0, 0) -> (m - 1, n - 1)
// 0 -> (m - 1) * n + (n - 1);

// m = 3, n = 4
// (0, 0) -> (2, 3)
// 0 -> 2 * 4 + 3 = 11
