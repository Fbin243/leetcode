/**
 * Author: Fbin
 * Link:https://leetcode.com/problems/set-matrix-zeroes/description/?envType=study-plan-v2&envId=top-interview-150
 * Created at: 28/04/2025
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  void setZeroes(vector<vector<int>>& matrix) {
    set<int> rows;
    set<int> cols;
    for (int i = 0; i < matrix.size(); i++) {
      for (int j = 0; j < matrix[0].size(); j++) {
        if (matrix[i][j] == 0) {
          rows.insert(i);
          cols.insert(j);
        }
      }
    }

    for (int i = 0; i < matrix.size(); i++) {
      for (int j = 0; j < matrix[0].size(); j++) {
        if (rows.find(i) != rows.end() || cols.find(j) != cols.end()) {
          matrix[i][j] = 0;
        }
      }
    }
  }
};
