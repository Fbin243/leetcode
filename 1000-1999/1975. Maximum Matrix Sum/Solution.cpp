/**
 * Author: Fbin
 * Link:https://leetcode.com/problems/maximum-matrix-sum/description/\?envType\=daily-question\&envId\=2026-01-05
 * Created at: 05/01/2026
 */

#include <fbin/leetcode.h>

class Solution {
 public:
  long long maxMatrixSum(vector<vector<int>>& matrix) {
    long long sum = 0;
    int neg = 0;
    int minVal = INT_MAX;
    for (int i = 0; i < matrix.size(); i++) {
      for (int j = 0; j < matrix[0].size(); j++) {
        minVal = min(minVal, abs(matrix[i][j]));
        sum += abs(matrix[i][j]);
        if (matrix[i][j] < 0) {
          neg++;
        }
      }
    }

    return neg % 2 ? sum - 2 * minVal : sum;
  }
};
