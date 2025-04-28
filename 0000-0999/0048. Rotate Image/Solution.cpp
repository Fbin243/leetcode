/**
 * Author: Fbin
 * Link:https://leetcode.com/problems/rotate-image/description/?envType=study-plan-v2&envId=top-interview-150
 * Created at: 28/04/2025
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  void rotate(vector<vector<int>>& matrix) {
    int n = matrix.size();
    int i = 0, startj = 0, endj = n - 1;
    while (i < n / 2) {
      for (int j = startj; j < endj; j++) {
        int i0 = i, j0 = j;
        int i1 = j0, j1 = n - 1 - i0;
        int temp = matrix[i0][j0];
        while (i1 != i || j1 != j) {
          swap(matrix[i1][j1], temp);
          i0 = i1;
          j0 = j1;
          i1 = j0;
          j1 = n - 1 - i0;
        }
        matrix[i1][j1] = temp;
      }
      startj++;
      endj--;
      i++;
    }
  }
};
