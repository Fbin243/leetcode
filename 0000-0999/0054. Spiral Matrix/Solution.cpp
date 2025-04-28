/**
 * Author: Fbin
 * Link:https://leetcode.com/problems/spiral-matrix/description/?envType=study-plan-v2&envId=top-interview-150
 * Created at: 28/04/2025
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  vector<int> spiralOrder(vector<vector<int>>& matrix) {
    int starti = 0, startj = 0;
    int endi = matrix.size() - 1, endj = matrix[0].size() - 1;
    int i = 0, j = 0;

    vector<int> res;
    while (starti <= endi && startj <= endj) {
      for (int j = startj; j <= endj; j++) {
        res.push_back(matrix[starti][j]);
      }
      starti++;
      for (int i = starti; i <= endi; i++) {
        res.push_back(matrix[i][endj]);
      }
      endj--;
      for (int j = endj; j >= startj; j--) {
        res.push_back(matrix[endi][j]);
      }
      endi--;
      for (int i = endi; i >= starti; i--) {
        res.push_back(matrix[i][startj]);
      }
      startj++;
    }
  }
};
